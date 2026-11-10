from hc_runtime import TreeNode


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        # Depth-first with an explicit stack (skewed trees of 10^5 nodes),
        # carrying the largest value on the path above each node: a node is
        # good when it is at least that large.
        count = 0
        stack = [(root, root.val)]
        while stack:
            node, high = stack.pop()
            if node.val >= high:
                count += 1
                high = node.val
            if node.left:
                stack.append((node.left, high))
            if node.right:
                stack.append((node.right, high))
        return count
