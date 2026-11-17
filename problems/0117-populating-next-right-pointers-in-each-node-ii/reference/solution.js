function connect(root) {
    let level = root;
    while (level !== null) {
        const dummy = new Node(0);
        let tail = dummy;
        let node = level;
        while (node !== null) {
            if (node.left !== null) {
                tail.next = node.left;
                tail = tail.next;
            }
            if (node.right !== null) {
                tail.next = node.right;
                tail = tail.next;
            }
            node = node.next;
        }
        level = dummy.next;
    }
    return root;
}
