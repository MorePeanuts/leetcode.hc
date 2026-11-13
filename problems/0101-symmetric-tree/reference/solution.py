class Solution:
    def isSymmetric(self, root):
        pairs = [(root.left, root.right)]
        while pairs:
            left, right = pairs.pop()
            if left is None or right is None:
                if left is not right:
                    return False
                continue
            if left.val != right.val:
                return False
            pairs.append((left.left, right.right))
            pairs.append((left.right, right.left))
        return True
