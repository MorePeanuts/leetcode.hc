from hc_runtime import NextTreeNode as Node

class Solution:
    def connect(self, root):
        level = root
        while level:
            dummy = Node(0)
            tail = dummy
            node = level
            while node:
                if node.left:
                    tail.next = node.left
                    tail = tail.next
                if node.right:
                    tail.next = node.right
                    tail = tail.next
                node = node.next
            level = dummy.next
        return root
