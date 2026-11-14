from hc_runtime import TreeNode


class Solution:
    def postorderTraversal(self, root: TreeNode | None) -> list[int]:
        result = []
        stack = [root] if root else []
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        result.reverse()
        return result
