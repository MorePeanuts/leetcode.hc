from hc_runtime import TreeNode


class Codec:
    # Level order, comma-separated, "#" for a missing child: the format of
    # the cases, "1,2,3,#,#,4,5". No recursion, so skewed trees of 10^4
    # nodes are fine.

    def serialize(self, root: TreeNode | None) -> str:
        out = []
        queue = [root]
        for node in queue:
            if node is None:
                out.append("#")
            else:
                out.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
        return ",".join(out)

    def deserialize(self, data: str) -> TreeNode | None:
        tokens = data.split(",")
        if tokens[0] == "#":
            return None
        root = TreeNode(int(tokens[0]))
        queue = [root]
        i = 1
        for node in queue:
            if tokens[i] != "#":
                node.left = TreeNode(int(tokens[i]))
                queue.append(node.left)
            if tokens[i + 1] != "#":
                node.right = TreeNode(int(tokens[i + 1]))
                queue.append(node.right)
            i += 2
        return root
