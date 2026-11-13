from hc_runtime import ListNode


class Solution:
    def isPalindrome(self, head: ListNode | None) -> bool:
        slow = fast = head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
        previous = None
        while slow is not None:
            following = slow.next
            slow.next = previous
            previous, slow = slow, following
        left, right = head, previous
        while right is not None:
            if left.val != right.val:
                return False
            left, right = left.next, right.next
        return True
