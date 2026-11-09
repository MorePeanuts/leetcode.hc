from hc_runtime import TreeNode


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode | None) -> int:
        # Post-order without recursion (skewed trees of 10^4 nodes): each
        # node's height in nodes is one more than its higher subtree's, and
        # the longest path turning at it has the sum of its subtrees' heights
        # as its length in edges.
        order, stack = [], [root]
        while stack:
            node = stack.pop()
            order.append(node)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        height = {None: 0}
        best = 0
        for node in reversed(order):
            left = height[node.left]
            right = height[node.right]
            if left + right > best:
                best = left + right
            height[node] = 1 + (left if left > right else right)
        return best
