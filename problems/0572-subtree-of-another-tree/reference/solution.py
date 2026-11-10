from hc_runtime import TreeNode


class Solution:
    def isSubtree(self, root: TreeNode | None, subRoot: TreeNode | None) -> bool:
        # Compare subRoot with the subtree at every node of root whose value
        # matches subRoot's, O(m * n) at worst. No recursion, so skewed trees
        # of 2000 nodes are fine.
        def same(a: TreeNode | None, b: TreeNode | None) -> bool:
            stack = [(a, b)]
            while stack:
                a, b = stack.pop()
                if a is None and b is None:
                    continue
                if a is None or b is None or a.val != b.val:
                    return False
                stack.append((a.left, b.left))
                stack.append((a.right, b.right))
            return True

        stack = [root]
        while stack:
            node = stack.pop()
            if node.val == subRoot.val and same(node, subRoot):
                return True
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return False
