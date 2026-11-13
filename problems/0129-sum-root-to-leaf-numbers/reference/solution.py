class Solution:
    def sumNumbers(self, root):
        total = 0
        stack = [(root, 0)] if root is not None else []
        while stack:
            node, prefix = stack.pop()
            number = prefix * 10 + node.val
            if node.left is None and node.right is None:
                total += number
            if node.left is not None:
                stack.append((node.left, number))
            if node.right is not None:
                stack.append((node.right, number))
        return total
