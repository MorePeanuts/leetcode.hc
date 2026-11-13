class Solution:
    def binaryTreePaths(self, root):
        if root is None:
            return []
        answer = []
        stack = [(root, str(root.val))]
        while stack:
            node, path = stack.pop()
            if node.left is None and node.right is None:
                answer.append(path)
            if node.right is not None:
                stack.append((node.right, path + "->" + str(node.right.val)))
            if node.left is not None:
                stack.append((node.left, path + "->" + str(node.left.val)))
        return answer
