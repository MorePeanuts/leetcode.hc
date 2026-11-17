function connect(root: _Node | null): _Node | null {
    let level: _Node | null = root;
    while (level !== null) {
        const dummy = new _Node(0, null, null, null);
        let tail: _Node = dummy;
        let node: _Node | null = level;
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
