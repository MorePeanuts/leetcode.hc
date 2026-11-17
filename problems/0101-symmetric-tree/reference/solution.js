function mirror(left, right) {
    if (left === null || right === null) {
        return left === right;
    }
    return left.val === right.val
        && mirror(left.left, right.right)
        && mirror(left.right, right.left);
}

function isSymmetric(root) {
    return root === null || mirror(root.left, root.right);
}
