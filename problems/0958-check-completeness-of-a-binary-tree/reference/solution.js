function isCompleteTree(root) {
    const queue = [root];
    let head = 0;
    let gap = false;
    while (head < queue.length) {
        let node = queue[head++];
        if (node === null) {
            gap = true;
        } else {
            if (gap) {
                return false;
            }
            queue.push(node.left);
            queue.push(node.right);
        }
    }
    return true;
}
