function maxPathSum(root: TreeNode | null): number {
    if (root === null) {
        return 0;
    }
    const stack = [{ node: root, stage: 0, leftGain: 0 }];
    let best = root.val;
    let gain = 0;
    while (stack.length > 0) {
        const frame = stack[stack.length - 1];
        if (frame.stage === 0) {
            frame.stage = 1;
            if (frame.node.left !== null) {
                stack.push({ node: frame.node.left, stage: 0, leftGain: 0 });
                continue;
            }
            gain = 0;
        }
        if (frame.stage === 1) {
            frame.leftGain = gain > 0 ? gain : 0;
            frame.stage = 2;
            if (frame.node.right !== null) {
                stack.push({ node: frame.node.right, stage: 0, leftGain: 0 });
                continue;
            }
            gain = 0;
        }
        const rightGain = gain > 0 ? gain : 0;
        const through = frame.node.val + frame.leftGain + rightGain;
        if (through > best) {
            best = through;
        }
        gain = frame.node.val + (frame.leftGain > rightGain ? frame.leftGain : rightGain);
        stack.pop();
    }

    return best;
}
