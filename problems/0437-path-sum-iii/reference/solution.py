class Solution:
    def pathSum(self, root, targetSum):
        if root is None:
            return 0
        prefix = {0: 1}
        answer = 0
        stack = [(root, 0, False)]
        while stack:
            node, total, leaving = stack.pop()
            if leaving:
                prefix[total] -= 1
                continue
            total += node.val
            answer += prefix.get(total - targetSum, 0)
            prefix[total] = prefix.get(total, 0) + 1
            stack.append((node, total, True))
            if node.right is not None:
                stack.append((node.right, total, False))
            if node.left is not None:
                stack.append((node.left, total, False))
        return answer
