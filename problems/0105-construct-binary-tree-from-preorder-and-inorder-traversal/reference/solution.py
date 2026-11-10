from hc_runtime import TreeNode


class Solution:
    def buildTree(self, preorder: list[int], inorder: list[int]) -> TreeNode | None:
        # One pass over preorder with a stack of the nodes whose right child
        # is still open, O(n) and without recursion (skewed trees of 3000
        # nodes). Each next value is the left child of the top of the stack,
        # unless inorder has already reached that node: then it is the right
        # child of the last node popped while inorder catches up.
        root = TreeNode(preorder[0])
        stack = [root]
        j = 0
        for v in preorder[1:]:
            node = TreeNode(v)
            parent = stack[-1]
            if parent.val != inorder[j]:
                parent.left = node
            else:
                while stack and stack[-1].val == inorder[j]:
                    parent = stack.pop()
                    j += 1
                parent.right = node
            stack.append(node)
        return root
