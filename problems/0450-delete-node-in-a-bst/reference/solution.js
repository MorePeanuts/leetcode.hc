function deleteNode(root, key) {
    let parent = null;
    let node = root;
    while (node !== null && node.val !== key) {
        parent = node;
        node = key < node.val ? node.left : node.right;
    }
    if (node === null) {
        return root;
    }
    if (node.left !== null && node.right !== null) {
        let successorParent = node;
        let successor = node.right;
        while (successor.left !== null) {
            successorParent = successor;
            successor = successor.left;
        }
        node.val = successor.val;
        parent = successorParent;
        node = successor;
    }
    let child = node.left !== null ? node.left : node.right;
    if (parent === null) {
        return child;
    }
    if (parent.left === node) {
        parent.left = child;
    } else {
        parent.right = child;
    }
    return root;
}
