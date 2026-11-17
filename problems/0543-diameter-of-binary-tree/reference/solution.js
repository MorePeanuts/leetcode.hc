function diameterOfBinaryTree(root) {
    if (root === null) {
        return 0;
    }
    const stack = [];
    stack.push({ node: root, phase: 0, left: 0 });
    let best = 0;
    let height = 0;
    while (stack.length > 0) {
        const frame = stack[stack.length - 1];
        if (frame.phase === 0) {
            frame.phase = 1;
            if (frame.node.left !== null) {
                stack.push({ node: frame.node.left, phase: 0, left: 0 });
                continue;
            }
            height = 0;
        }
        if (frame.phase === 1) {
            frame.left = height;
            frame.phase = 2;
            if (frame.node.right !== null) {
                stack.push({ node: frame.node.right, phase: 0, left: 0 });
                continue;
            }
            height = 0;
        }
        let through = frame.left + height;
        if (through > best) {
            best = through;
        }
        height = (frame.left > height ? frame.left : height) + 1;
        stack.pop();
    }

    return best;
}
