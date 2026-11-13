class Solution:
    def zigzagLevelOrder(self, root):
        if root is None:
            return []
        result = []
        level = [root]
        while level:
            row = [node.val for node in level]
            if len(result) % 2 == 1:
                row.reverse()
            result.append(row)
            level = [child for node in level for child in (node.left, node.right) if child]
        return result
