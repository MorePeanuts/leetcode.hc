from hc_runtime import ListNode


class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        # One pass: the lead pointer runs n nodes ahead, so when it reaches
        # the tail the other one is just before the node to remove.
        dummy = ListNode(0, head)
        lead = trail = dummy
        for _ in range(n):
            lead = lead.next
        while lead.next:
            lead = lead.next
            trail = trail.next
        trail.next = trail.next.next
        return dummy.next
