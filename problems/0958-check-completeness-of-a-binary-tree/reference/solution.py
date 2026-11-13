class Solution:
    def isCompleteTree(self, root):
        queue = [root]
        gap = False
        for node in queue:
            if node is None:
                gap = True
            else:
                if gap:
                    return False
                queue.append(node.left)
                queue.append(node.right)
        return True
