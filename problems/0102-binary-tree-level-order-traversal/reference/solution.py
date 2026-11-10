from hc_runtime import TreeNode


class Solution:
    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
        # Breadth-first, one level at a time, children left to right.
        result = []
        level = [root] if root else []
        while level:
            result.append([n.val for n in level])
            level = [c for n in level for c in (n.left, n.right) if c]
        return result
