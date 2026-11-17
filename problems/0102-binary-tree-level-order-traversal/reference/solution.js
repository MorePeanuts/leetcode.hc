function levelOrder(root) {
    const result = [];
    if (root === null) return result;
    const queue = [];
    queue.push(root);
    for (let head = 0; head < queue.length;) {
        let limit = queue.length;
        const values = [];
        for (let i = 0; head < limit; i++) {
            const node = queue[head++];
            values.push(node.val);
            if (node.left !== null) queue.push(node.left);
            if (node.right !== null) queue.push(node.right);
        }
        result.push(values);
    }
    return result;
}
