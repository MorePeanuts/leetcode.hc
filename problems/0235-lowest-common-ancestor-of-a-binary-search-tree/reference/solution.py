from hc_runtime import TreeNode


class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # Walk down from the root: while p and q are both on one side of the
        # node, go to that side; the first node that separates them (or is
        # one of them) is their lowest common ancestor. O(height).
        lo, hi = (p.val, q.val) if p.val < q.val else (q.val, p.val)
        node = root
        while True:
            if hi < node.val:
                node = node.left
            elif lo > node.val:
                node = node.right
            else:
                return node
