function binaryTreePaths(root) {
    const result = [];
    function visit(node, path) {
        if (node === null) {
            return;
        }
        const next = path.length === 0 ? String(node.val) : path + "->" + node.val;
        if (node.left === null && node.right === null) {
            result.push(next);
            return;
        }
        visit(node.left, next);
        visit(node.right, next);
    }
    visit(root, "");
    return result;
}
