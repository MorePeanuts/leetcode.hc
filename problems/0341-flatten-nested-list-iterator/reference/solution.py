from hc_runtime import NestedInteger


class NestedIterator:
    def __init__(self, nestedList: list[NestedInteger]):
        self.stack = list(reversed(nestedList))

    def next(self) -> int:
        self.hasNext()
        return self.stack.pop().getInteger()

    def hasNext(self) -> bool:
        while self.stack and not self.stack[-1].isInteger():
            self.stack.extend(reversed(self.stack.pop().getList()))
        return bool(self.stack)
