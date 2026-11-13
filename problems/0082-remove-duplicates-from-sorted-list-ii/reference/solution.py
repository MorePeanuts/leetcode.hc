from hc_runtime import ListNode

class Solution:
    def deleteDuplicates(self, head):
        dummy = ListNode(0, head)
        previous = dummy
        current = head
        while current:
            if current.next and current.val == current.next.val:
                value = current.val
                while current and current.val == value:
                    current = current.next
                previous.next = current
            else:
                previous = current
                current = current.next
        return dummy.next
