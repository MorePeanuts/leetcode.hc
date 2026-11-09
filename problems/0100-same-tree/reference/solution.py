from hc_runtime import TreeNode


class Solution:
    def isSameTree(self, p: TreeNode | None, q: TreeNode | None) -> bool:
        # Walk both trees in step with a stack of node pairs: each pair must
        # be both missing, or both present with equal values.
        stack = [(p, q)]
        while stack:
            a, b = stack.pop()
            if a is None and b is None:
                continue
            if a is None or b is None or a.val != b.val:
                return False
            stack.append((a.left, b.left))
            stack.append((a.right, b.right))
        return True
