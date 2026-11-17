function sameTree(first, second) {
    if (first === null || second === null) {
        return first === second;
    }
    return first.val === second.val
        && sameTree(first.left, second.left)
        && sameTree(first.right, second.right);
}

function isSubtree(root, subRoot) {
    if (root === null) {
        return subRoot === null;
    }
    return sameTree(root, subRoot)
        || isSubtree(root.left, subRoot)
        || isSubtree(root.right, subRoot);
}
