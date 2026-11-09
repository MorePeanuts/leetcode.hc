from hc_runtime import RandomListNode as Node


class Solution:
    def copyRandomList(self, head: Node | None) -> Node | None:
        # Map each original node to its copy, then link the copies.
        copies = {None: None}
        node = head
        while node:
            copies[node] = Node(node.val)
            node = node.next
        node = head
        while node:
            copy = copies[node]
            copy.next = copies[node.next]
            copy.random = copies[node.random]
            node = node.next
        return copies[head]
