from hc_runtime import TreeNode


class Solution:
    def maxPathSum(self, root: TreeNode | None) -> int:
        # Post-order without recursion (skewed trees of 3 * 10^4 nodes): each
        # node's gain is its value plus the better non-negative child gain,
        # and the best path turning at it adds both.
        order, stack = [], [root]
        while stack:
            node = stack.pop()
            order.append(node)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        gain = {}
        best = root.val
        for node in reversed(order):
            left = max(gain.get(node.left, 0), 0)
            right = max(gain.get(node.right, 0), 0)
            best = max(best, node.val + left + right)
            gain[node] = node.val + max(left, right)
        return best
