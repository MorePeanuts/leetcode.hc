from hc_runtime import ListNode

class Solution:
    def sortList(self, head: ListNode | None) -> ListNode | None:
        def split(node, size):
            if node is None:
                return None
            for _ in range(size - 1):
                if node.next is None:
                    break
                node = node.next
            rest = node.next
            node.next = None
            return rest

        length = 0
        node = head
        while node is not None:
            length += 1
            node = node.next
        dummy = ListNode(0, head)
        size = 1
        while size < length:
            tail, current = dummy, dummy.next
            while current is not None:
                left = current
                right = split(left, size)
                current = split(right, size)
                while left is not None and right is not None:
                    if left.val <= right.val:
                        tail.next, left = left, left.next
                    else:
                        tail.next, right = right, right.next
                    tail = tail.next
                tail.next = left if left is not None else right
                while tail.next is not None:
                    tail = tail.next
            size *= 2
        return dummy.next
