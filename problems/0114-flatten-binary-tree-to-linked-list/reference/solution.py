from hc_runtime import TreeNode

class Solution:
    def flatten(self, root: TreeNode | None) -> None:
        while root is not None:
            if root.left is not None:
                predecessor = root.left
                while predecessor.right is not None:
                    predecessor = predecessor.right
                predecessor.right = root.right
                root.right = root.left
                root.left = None
            root = root.right
