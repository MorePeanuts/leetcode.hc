import bisect


class TimeMap:
    def __init__(self):
        # key -> its timestamps and values, in the order set was called. The
        # timestamps of set are strictly increasing, so each list is sorted.
        self.times: dict[str, list[int]] = {}
        self.values: dict[str, list[str]] = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.times:
            self.times[key] = []
            self.values[key] = []
        self.times[key].append(timestamp)
        self.values[key].append(value)

    def get(self, key: str, timestamp: int) -> str:
        times = self.times.get(key)
        if times is None:
            return ""
        i = bisect.bisect_right(times, timestamp)
        return self.values[key][i - 1] if i else ""
