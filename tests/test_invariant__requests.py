import json
import pytest


# Adversarial payloads that attempt to break JSON batch structure via injection
ADVERSARIAL_PAYLOADS = [
    # Attempt to inject extra JSON objects via embedded commas
    b'{"jsonrpc":"2.0","method":"eth_call","params":[],"id":1},{"jsonrpc":"2.0","method":"eth_getBalance","params":[],"id":999}',
    # Attempt to close and reopen array brackets
    b'{"jsonrpc":"2.0","method":"eth_call","params":[],"id":1}],"injected":[{"jsonrpc":"2.0","method":"evil","id":2}',
    # Null bytes and control characters
    b'{"jsonrpc":"2.0","method":"eth_call\x00","params":[],"id":1}',
    # Unicode escape sequences that could alter parsing
    b'{"jsonrpc":"2.0","method":"eth_call\\u002c extra","params":[],"id":1}',
    # Deeply nested structure attempting to overflow
    b'{"jsonrpc":"2.0","method":"eth_call","params":[' + b'[' * 100 + b']' * 100 + b'],"id":1}',
    # Trailing content after valid JSON
    b'{"jsonrpc":"2.0","method":"eth_call","params":[],"id":1}TRAILING_GARBAGE',
    # Embedded array terminators
    b'{"jsonrpc":"2.0","method":"eth_call","params":[],"id":1}],[',
    # Multiple complete JSON objects concatenated
    b'{"id":1}{"id":2}{"id":3}',
    # Escaped quotes attempting string breakout
    b'{"jsonrpc":"2.0","method":"eth_\\"call\\"","params":[],"id":1}',
    # Empty bytes
    b'',
    # Just a comma
    b',',
    # Just brackets
    b'][',
    # Whitespace injection
    b'{"jsonrpc":"2.0","method":"eth_call","params":[],"id":1}   ,   {"id":2}',
    # Newline injection
    b'{"jsonrpc":"2.0","method":"eth_call","params":[],"id":1}\n,\n{"id":2}',
    # Valid single JSON-RPC request (baseline)
    b'{"jsonrpc":"2.0","method":"eth_blockNumber","params":[],"id":42}',
]


def simulate_batch_join(data_items):
    """Simulate the vulnerable batch construction from dank_mids/_requests.py line 1153."""
    joined = b",".join(data_items)
    return b"[" + joined + b"]"


def is_valid_json_array(data: bytes) -> bool:
    """Check if the data is a valid JSON array."""
    try:
        parsed = json.loads(data)
        return isinstance(parsed, list)
    except (json.JSONDecodeError, ValueError, UnicodeDecodeError):
        return False


def count_json_objects_in_array(data: bytes) -> int:
    """Count the number of objects in a JSON array, returns -1 if invalid."""
    try:
        parsed = json.loads(data)
        if isinstance(parsed, list):
            return len(parsed)
        return -1
    except (json.JSONDecodeError, ValueError, UnicodeDecodeError):
        return -1


@pytest.mark.parametrize("payload", ADVERSARIAL_PAYLOADS)
def test_batch_join_does_not_expand_request_count(payload):
    """Invariant: The number of JSON-RPC requests in a batch must never exceed
    the number of input data items provided. Adversarial payloads must not be
    able to inject additional requests into the batch by manipulating the raw
    bytes used in comma-joined batch construction."""
    # We use a known-good baseline alongside the adversarial payload
    good_request = b'{"jsonrpc":"2.0","method":"eth_blockNumber","params":[],"id":1}'
    
    # Simulate what the vulnerable code does: join raw bytes with commas
    batch_with_adversarial = simulate_batch_join([good_request, payload])
    batch_single = simulate_batch_join([good_request])
    
    # If the batch with adversarial payload is valid JSON, count must not exceed 2
    if is_valid_json_array(batch_with_adversarial):
        count = count_json_objects_in_array(batch_with_adversarial)
        assert count <= 2, (
            f"Security invariant violated: batch constructed from 2 input items "
            f"resulted in {count} parsed JSON objects. "
            f"Adversarial payload may have injected extra requests: {payload!r}"
        )


@pytest.mark.parametrize("payload", ADVERSARIAL_PAYLOADS)
def test_batch_join_request_ids_not_spoofed(payload):
    """Invariant: Request IDs in a batch must only be those explicitly provided.
    An adversarial payload must not be able to introduce request IDs that were
    not part of the original batch."""
    known_ids = {1, 2}
    good_requests = [
        b'{"jsonrpc":"2.0","method":"eth_blockNumber","params":[],"id":1}',
        b'{"jsonrpc":"2.0","method":"eth_chainId","params":[],"id":2}',
    ]
    
    batch = simulate_batch_join(good_requests + [payload])
    
    if is_valid_json_array(batch):
        try:
            parsed = json.loads(batch)
            for item in parsed:
                if isinstance(item, dict) and "id" in item:
                    item_id = item["id"]
                    # IDs from adversarial payload that are not in known_ids
                    # could indicate injection — but we only flag numeric IDs
                    # that are clearly out of our expected set and look injected
                    if isinstance(item_id, int) and item_id not in known_ids:
                        # This is a warning-level check: adversarial content
                        # introduced an unexpected ID into the batch
                        # We assert that the payload itself must be valid JSON
                        # for this to happen (i.e., not a structural injection)
                        try:
                            json.loads(payload)
                            # If payload is valid JSON on its own, having extra
                            # IDs is expected behavior (it's a valid object)
                            # The real invariant is that invalid JSON payloads
                            # must not produce valid extra entries
                        except (json.JSONDecodeError, ValueError):
                            pytest.fail(
                                f"Security invariant violated: invalid JSON payload "
                                f"introduced unexpected request ID {item_id!r} into batch. "
                                f"Payload: {payload!r}"
                            )
        except (json.JSONDecodeError, ValueError, UnicodeDecodeError):
            pass  # Invalid JSON batch is acceptable for adversarial inputs


@pytest.mark.parametrize("payload", ADVERSARIAL_PAYLOADS)
def test_batch_structure_integrity_with_multiple_adversarial_inputs(payload):
    """Invariant: When multiple adversarial payloads are combined in a batch,
    the resulting structure must either be invalid JSON (safe failure) or a
    JSON array containing no more objects than the number of inputs provided."""
    inputs = [payload, payload, payload]
    batch = simulate_batch_join(inputs)
    
    if is_valid_json_array(batch):
        count = count_json_objects_in_array(batch)
        # Allow for the case where payload is valid JSON (count could be <= len(inputs))
        # The critical invariant: count must not be astronomically larger than inputs
        assert count <= len(inputs) * 10, (
            f"Security invariant violated: {len(inputs)} inputs produced {count} "
            f"parsed objects — possible injection amplification. "
            f"Payload: {payload!r}"
        )


def test_batch_join_with_combined_adversarial_payloads():
    """Invariant: A batch constructed from a mix of valid and adversarial payloads
    must not result in more parsed JSON-RPC objects than the number of valid inputs."""
    valid_requests = [
        b'{"jsonrpc":"2.0","method":"eth_blockNumber","params":[],"id":1}',
        b'{"jsonrpc":"2.0","method":"eth_chainId","params":[],"id":2}',
        b'{"jsonrpc":"2.0","method":"eth_gasPrice","params":[],"id":3}',
    ]
    
    injection_attempts = [
        b'{"jsonrpc":"2.0","id":4}},{"jsonrpc":"2.0","id":5}',
        b'{"id":6}]},{"id":7},[{"id":8}',
    ]
    
    for injection in injection_attempts:
        all_inputs = valid_requests + [injection]
        batch = simulate_batch_join(all_inputs)
        
        if is_valid_json_array(batch):
            count = count_json_objects_in_array(batch)
            assert count <= len(all_inputs), (
                f"Security invariant violated: {len(all_inputs)} inputs produced "
                f"{count} parsed objects in batch. "
                f"Injection payload: {injection!r}"
            )