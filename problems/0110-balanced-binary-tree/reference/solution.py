from hc_runtime import TreeNode


class Solution:
    def isBalanced(self, root: TreeNode | None) -> bool:
        # Post-order without recursion (skewed trees of 5000 nodes): each
        # node's height is computed once from its children's, and the first
        # node whose subtrees differ by more than one ends the walk.
        order, stack = [], [root] if root else []
        while stack:
            node = stack.pop()
            order.append(node)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        height = {None: 0}
        for node in reversed(order):
            left = height[node.left]
            right = height[node.right]
            if left - right > 1 or right - left > 1:
                return False
            height[node] = 1 + (left if left > right else right)
        return True
