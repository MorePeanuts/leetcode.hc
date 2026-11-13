from hc_runtime import TreeNode

class Solution:
    def buildTree(self, inorder, postorder):
        root = TreeNode(postorder[-1])
        stack = [root]
        index = len(inorder) - 1
        for value in reversed(postorder[:-1]):
            node = stack[-1]
            child = TreeNode(value)
            if node.val != inorder[index]:
                node.right = child
            else:
                while stack and stack[-1].val == inorder[index]:
                    node = stack.pop()
                    index -= 1
                node.left = child
            stack.append(child)
        return root
