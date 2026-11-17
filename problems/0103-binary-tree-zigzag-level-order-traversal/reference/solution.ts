function zigzagLevelOrder(root: TreeNode | null): number[][] {
    const result: number[][] = [];
    if (root === null) {
        return result;
    }
    const queue = [];
    queue.push(root);
    let head = 0;
    let forward = true;
    while (head < queue.length) {
        let end = queue.length;
        let width = end - head;
        const row: number[] = Array(width);
        for (let i = 0; i < width; i++) {
            const node = queue[head++];
            row[forward ? i : width - 1 - i] = node.val;
            if (node.left !== null) {
                queue.push(node.left);
            }
            if (node.right !== null) {
                queue.push(node.right);
            }
        }
        result.push(row);
        forward = !forward;
    }
    return result;
}
