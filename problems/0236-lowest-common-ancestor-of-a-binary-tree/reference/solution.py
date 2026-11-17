from hc_runtime import TreeNode

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        parents = {root: None}
        stack = [root]
        while p not in parents or q not in parents:
            node = stack.pop()
            for child in (node.left, node.right):
                if child is not None:
                    parents[child] = node
                    stack.append(child)
        ancestors = set()
        while p is not None:
            ancestors.add(p)
            p = parents[p]
        while q not in ancestors:
            q = parents[q]
        return q
