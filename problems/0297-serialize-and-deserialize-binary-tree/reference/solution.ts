function serialize(root: TreeNode | null): string {
    const queue: (TreeNode | null)[] = [root];
    const tokens: string[] = [];
    for (let i = 0; i < queue.length; i++) {
        const node = queue[i];
        if (node === null) {
            tokens.push("#");
        } else {
            tokens.push(String(node.val));
            queue.push(node.left, node.right);
        }
    }
    return tokens.join(",");
}

function deserialize(data: string): TreeNode | null {
    const tokens = data.split(",");
    const queue: TreeNode[] = [];
    let next = 0;

    function readNode(): TreeNode | null {
        const token = tokens[next++];
        if (token === "#") return null;
        const node = new TreeNode(Number(token));
        queue.push(node);
        return node;
    }

    const root = readNode();
    for (let i = 0; i < queue.length; i++) {
        const parent = queue[i];
        parent.left = readNode();
        parent.right = readNode();
    }
    return root;
}
