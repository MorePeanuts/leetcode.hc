function convertBST(root) {
    const stack = [];
    let total = 0;
    let node = root;
    while (node !== null || stack.length > 0) {
        while (node !== null) {
            stack.push(node);
            node = node.right;
        }
        node = stack[stack.length - 1];
        stack.pop();
        total += node.val;
        node.val = total;
        node = node.left;
    }
    return root;
}
