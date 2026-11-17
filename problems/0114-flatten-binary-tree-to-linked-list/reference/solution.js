function flatten(root) {
    let current = root;
    while (current !== null) {
        if (current.left !== null) {
            let predecessor = current.left;
            while (predecessor.right !== null) {
                predecessor = predecessor.right;
            }
            predecessor.right = current.right;
            current.right = current.left;
            current.left = null;
        }
        current = current.right;
    }
}
