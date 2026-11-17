function sumFrom(node: TreeNode | null, prefix: number): number {
    if (node === null) {
        return 0;
    }
    let value = prefix * 10 + node.val;
    if (node.left === null && node.right === null) {
        return value;
    }
    return sumFrom(node.left, value) + sumFrom(node.right, value);
}

function sumNumbers(root: TreeNode | null): number {
    return sumFrom(root, 0);
}
