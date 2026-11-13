from collections import deque
from hc_runtime import TreeNode


class Solution:
    def minDepth(self, root: TreeNode | None) -> int:
        if root is None:
            return 0
        queue = deque([root])
        depth = 1
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left is None and node.right is None:
                    return depth
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
            depth += 1
        return 0
