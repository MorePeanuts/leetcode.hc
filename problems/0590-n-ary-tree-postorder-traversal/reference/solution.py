from hc_runtime import NaryNode as Node


class Solution:
    def postorder(self, root: Node | None) -> list[int]:
        result = []
        stack = [root] if root else []
        while stack:
            node = stack.pop()
            result.append(node.val)
            stack.extend(node.children)
        result.reverse()
        return result
