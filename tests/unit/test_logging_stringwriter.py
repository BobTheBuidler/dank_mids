from dank_mids.logging import get_c_logger


def _find_caller_with_stack_info() -> str:
    logger = get_c_logger("dank_mids.tests.logging")
    _filename, _line, _function, stack_info = logger.findCaller(stack_info=True)
    assert stack_info is not None
    return stack_info


def test_find_caller_stack_info_is_plain_stack_text() -> None:
    stack_info = _find_caller_with_stack_info()

    assert stack_info.startswith("Stack (most recent call last):")
    assert "_find_caller_with_stack_info" in stack_info
    assert stack_info[-1] != "\n"
