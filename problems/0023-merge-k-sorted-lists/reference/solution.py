import heapq

from hc_runtime import ListNode


class Solution:
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        # A heap of the lists' current heads; the index breaks ties between
        # equal values, so nodes are never compared.
        heap = [(node.val, i, node) for i, node in enumerate(lists) if node]
        heapq.heapify(heap)
        dummy = tail = ListNode()
        while heap:
            _, i, node = heap[0]
            tail.next = node
            tail = node
            if node.next:
                heapq.heapreplace(heap, (node.next.val, i, node.next))
            else:
                heapq.heappop(heap)
        tail.next = None
        return dummy.next
