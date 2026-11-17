function preorderTraversal(root) {
    const result = [];
    if (root === null) {
        return result;
    }
    const stack = [];
    stack.push(root);
    while (stack.length > 0) {
        const node = stack.pop();
        result.push(node.val);
        if (node.right !== null) {
            stack.push(node.right);
        }
        if (node.left !== null) {
            stack.push(node.left);
        }
    }
    return result;
}
