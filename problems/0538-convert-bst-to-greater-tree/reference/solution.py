class Solution:
    def convertBST(self, root):
        total = 0
        stack = []
        node = root
        while node is not None or stack:
            while node is not None:
                stack.append(node)
                node = node.right
            node = stack.pop()
            total += node.val
            node.val = total
            node = node.left
        return root
