from hc_runtime import TreeNode


class Solution:
    def invertTree(self, root: TreeNode | None) -> TreeNode | None:
        # Swap the children of every node, with an explicit stack.
        stack = [root] if root else []
        while stack:
            node = stack.pop()
            node.left, node.right = node.right, node.left
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return root
