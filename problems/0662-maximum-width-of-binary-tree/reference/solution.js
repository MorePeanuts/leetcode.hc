function widthOfBinaryTree(root) {
    if (root === null) {
        return 0;
    }
    const queue = [{node: root, index: 0}];
    let head = 0;
    let best = 0;
    while (head < queue.length) {
        let end = queue.length;
        const base = queue[head].index;
        let width = (queue[end - 1].index - base + 1);
        if (width > best) {
            best = width;
        }
        while (head < end) {
            const node = queue[head].node;
            const index = queue[head].index - base;
            head++;
            if (node.left !== null) {
                queue.push({node: node.left, index: 2 * index});
            }
            if (node.right !== null) {
                queue.push({node: node.right, index: 2 * index + 1});
            }
        }
    }
    return best;
}
