function goodNodes(root) {
    if (root === null) {
        return 0;
    }
    const stack = [{ node: root, high: root.val }];
    let result = 0;
    while (stack.length > 0) {
        const entry = stack[stack.length - 1];
        stack.pop();
        let high = entry.high;
        if (entry.node.val >= high) {
            result++;
            high = entry.node.val;
        }
        if (entry.node.left !== null) {
            stack.push({ node: entry.node.left, high });
        }
        if (entry.node.right !== null) {
            stack.push({ node: entry.node.right, high });
        }
    }

    return result;
}
