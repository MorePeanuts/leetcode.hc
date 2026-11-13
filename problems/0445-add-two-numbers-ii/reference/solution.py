from hc_runtime import ListNode

class Solution:
    def addTwoNumbers(self, l1, l2):
        first, second = [], []
        while l1:
            first.append(l1.val)
            l1 = l1.next
        while l2:
            second.append(l2.val)
            l2 = l2.next
        carry = 0
        head = None
        while first or second or carry:
            total = carry
            if first:
                total += first.pop()
            if second:
                total += second.pop()
            carry, digit = divmod(total, 10)
            head = ListNode(digit, head)
        return head
