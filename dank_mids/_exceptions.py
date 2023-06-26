
class BadResponse(Exception):
    def __init__(self, *args) -> None:
        if len(args) == 1:
            arg = args[0]
            if isinstance(arg, dict) and 'result' in arg:
                arg = arg['result']
            if isinstance(arg, dict) and 'message' in arg:
                arg = arg['message']
            args = (arg)
        super().__init__(*args)

class EmptyBatch(Exception):
    pass
