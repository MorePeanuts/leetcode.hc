from random import randrange
from hc_runtime import ListNode


class Solution:
    def __init__(self, head: ListNode):
        self.head = head

    def getRandom(self) -> int:
        result = self.head.val
        node = self.head
        count = 1
        while node is not None:
            if randrange(count) == 0:
                result = node.val
            count += 1
            node = node.next
        return result
