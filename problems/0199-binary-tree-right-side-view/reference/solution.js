function rightSideView(root) {
    const result = [];
    if (root === null) {
        return result;
    }
    const stack = [];
    const depths = [];
    stack.push(root);
    depths.push(0);
    while (stack.length > 0) {
        const node = stack.pop();
        let depth = depths.pop();
        if (depth === result.length) {
            result.push(node.val);
        }
        if (node.left !== null) {
            stack.push(node.left);
            depths.push(depth + 1);
        }
        if (node.right !== null) {
            stack.push(node.right);
            depths.push(depth + 1);
        }
    }
    return result;
}
