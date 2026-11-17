function distanceK(root: TreeNode, target: TreeNode, k: number): number[] {
    const parents = new Array<TreeNode | null>(501).fill(null);
    const queue: TreeNode[] = [];
    const seen = new Uint8Array(501);
    queue[0] = root;
    let tail = 1;
    for (let head = 0; head < tail; head++) {
        const node = queue[head];
        if (node.left !== null) {
            parents[node.left.val] = node;
            queue[tail++] = node.left;
        }
        if (node.right !== null) {
            parents[node.right.val] = node;
            queue[tail++] = node.right;
        }
    }
    queue[0] = target;
    seen[target.val] = 1;
    tail = 1;
    let head = 0;
    for (let depth = 0; depth < k && head < tail; depth++) {
        let levelEnd = tail;
        for (; head < levelEnd; head++) {
            const node = queue[head];
            const neighbors = [node.left, node.right, parents[node.val]];
            for (const neighbor of neighbors) {

                if (neighbor !== null && !seen[neighbor.val]) {
                    seen[neighbor.val] = 1;
                    queue[tail++] = neighbor;
                }
            }
        }
    }
    return queue.slice(head, tail).map(node => node.val);
}
