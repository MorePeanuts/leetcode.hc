function postorder(root) {
    const result = [];
    if (root === null) {
        return result;
    }
    const stack = [];
    stack.push(root);
    while (stack.length > 0) {
        const node = stack.pop();
        result.push(node.val);
        for (const child of node.children) {
            stack.push(child);
        }
    }
    result.reverse();
    return result;
}
