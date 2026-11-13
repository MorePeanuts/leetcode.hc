from hc_runtime import TreeNode


class Solution:
    def preorderTraversal(self, root: TreeNode | None) -> list[int]:
        if root is None:
            return []
        result = []
        stack = [root]
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.right is not None:
                stack.append(node.right)
            if node.left is not None:
                stack.append(node.left)
        return result
