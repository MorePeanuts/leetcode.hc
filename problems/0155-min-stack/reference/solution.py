class MinStack:
    # Each entry keeps the minimum of the stack up to and including it.

    def __init__(self):
        self.stack = []

    def push(self, value: int) -> None:
        if self.stack:
            self.stack.append((value, min(value, self.stack[-1][1])))
        else:
            self.stack.append((value, value))

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]
