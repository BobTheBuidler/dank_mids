
from dank_mids._debugging._base import _CSVWriter

class FailedRequestWriter(_CSVWriter):
    filename = "/failed_requests.csv"
    async def record_failure(self, e: Exception, request_data: bytes):
        row = type(e).__name__, str(e), request_data.hex()
        await self.write_row(','.join(row))

record = FailedRequestWriter().record_failure