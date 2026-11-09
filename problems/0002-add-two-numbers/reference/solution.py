from hc_runtime import ListNode


class Solution:
    def addTwoNumbers(
        self, l1: ListNode | None, l2: ListNode | None
    ) -> ListNode | None:
        # Schoolbook addition from the least significant digit.
        dummy = tail = ListNode()
        carry = 0
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            carry, digit = divmod(carry, 10)
            tail.next = ListNode(digit)
            tail = tail.next
        return dummy.next
