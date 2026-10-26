from dank_mids.semaphores import BlockSemaphore


def test_block_semaphore_accepts_pending_tag() -> None:
    semaphore = BlockSemaphore(1)
    context = semaphore["pending"]

    assert context._priority == -1


def test_block_semaphore_accepts_latest_tag() -> None:
    semaphore = BlockSemaphore(1)
    context = semaphore["latest"]

    assert context._priority == -1


def test_tag_block_identifiers_are_distinct_from_numeric_blocks() -> None:
    semaphore = BlockSemaphore(1)
    numeric_context = semaphore[42]

    assert numeric_context._priority == 42
