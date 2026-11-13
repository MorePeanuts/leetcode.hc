from bisect import bisect_left


class MyCalendar:
    def __init__(self):
        self.events = []

    def book(self, startTime: int, endTime: int) -> bool:
        i = bisect_left(self.events, (startTime, endTime))
        if i > 0 and self.events[i - 1][1] > startTime:
            return False
        if i < len(self.events) and self.events[i][0] < endTime:
            return False
        self.events.insert(i, (startTime, endTime))
        return True
