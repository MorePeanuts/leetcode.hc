class Solution:
    def widthOfBinaryTree(self, root):
        level = [(root, 0)]
        widest = 0
        while level:
            widest = max(widest, level[-1][1] - level[0][1] + 1)
            base = level[0][1]
            next_level = []
            for node, index in level:
                index -= base
                if node.left:
                    next_level.append((node.left, 2 * index))
                if node.right:
                    next_level.append((node.right, 2 * index + 1))
            level = next_level
        return widest
