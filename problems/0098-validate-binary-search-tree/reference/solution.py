from hc_runtime import TreeNode


class Solution:
    def isValidBST(self, root: TreeNode | None) -> bool:
        # Iterative in-order traversal: the values must strictly increase.
        # No recursion, so skewed trees of 10^4 nodes are fine.
        stack = []
        prev = None
        node = root
        while stack or node:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            if prev is not None and node.val <= prev:
                return False
            prev = node.val
            node = node.right
        return True
