from collections import OrderedDict


class LFUCache:
    # Keys grouped by use counter, each group in least recently used order,
    # and the smallest counter in use: every call is O(1).

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.values = {}
        self.counts = {}
        self.groups = {}  # use counter -> OrderedDict of its keys
        self.min_count = 0

    def _touch(self, key: int) -> None:
        count = self.counts[key]
        group = self.groups[count]
        del group[key]
        if not group:
            del self.groups[count]
            if self.min_count == count:
                self.min_count = count + 1
        self.counts[key] = count + 1
        self.groups.setdefault(count + 1, OrderedDict())[key] = None

    def get(self, key: int) -> int:
        if key not in self.values:
            return -1
        self._touch(key)
        return self.values[key]

    def put(self, key: int, value: int) -> None:
        if key in self.values:
            self.values[key] = value
            self._touch(key)
            return
        if len(self.values) == self.capacity:
            group = self.groups[self.min_count]
            old, _ = group.popitem(last=False)
            if not group:
                del self.groups[self.min_count]
            del self.values[old]
            del self.counts[old]
        self.values[key] = value
        self.counts[key] = 1
        self.groups.setdefault(1, OrderedDict())[key] = None
        self.min_count = 1
