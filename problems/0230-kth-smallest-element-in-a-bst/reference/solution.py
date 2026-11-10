from hc_runtime import TreeNode


class Solution:
    def kthSmallest(self, root: TreeNode | None, k: int) -> int:
        # In-order traversal with an explicit stack (skewed trees of 10^4
        # nodes), stopping at the k-th node it visits.
        stack = []
        node = root
        while True:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            k -= 1
            if k == 0:
                return node.val
            node = node.right
