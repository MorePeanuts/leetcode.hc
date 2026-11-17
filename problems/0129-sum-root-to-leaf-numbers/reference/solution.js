function sumFrom(node, prefix) {
    if (node === null) {
        return 0;
    }
    let value = prefix * 10 + node.val;
    if (node.left === null && node.right === null) {
        return value;
    }
    return sumFrom(node.left, value) + sumFrom(node.right, value);
}

function sumNumbers(root) {
    return sumFrom(root, 0);
}
