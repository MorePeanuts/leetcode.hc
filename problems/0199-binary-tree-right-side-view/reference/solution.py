from hc_runtime import TreeNode


class Solution:
    def rightSideView(self, root: TreeNode | None) -> list[int]:
        # Breadth-first, one level at a time: the last node of each level is
        # the one seen from the right.
        view = []
        level = [root] if root else []
        while level:
            view.append(level[-1].val)
            level = [c for n in level for c in (n.left, n.right) if c]
        return view
