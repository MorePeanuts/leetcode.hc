from hc_runtime import TreeNode


class Solution:
    def maxDepth(self, root: TreeNode | None) -> int:
        # Breadth-first, one level at a time: the depth is the number of
        # levels. No recursion, so skewed trees of 10^4 nodes are fine.
        depth = 0
        level = [root] if root else []
        while level:
            depth += 1
            level = [c for n in level for c in (n.left, n.right) if c]
        return depth
