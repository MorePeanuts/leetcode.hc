function levelOrder(root: _Node | null): number[][] {
    if (root === null) return [];
    const queue = [root];
    const result: number[][] = [];
    for (let head = 0; head < queue.length;) {
        const end = queue.length;
        const level: number[] = [];
        for (; head < end; head++) {
            const node = queue[head];
            level.push(node.val);
            for (const child of node.children) queue.push(child);
        }
        result.push(level);
    }
    return result;
}
