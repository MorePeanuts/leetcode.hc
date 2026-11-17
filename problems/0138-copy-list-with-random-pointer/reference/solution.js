function copyRandomList(head) {
    if (head === null) {
        return null;
    }
    for (let node = head; node !== null; node = node.next.next) {
        const copy = new Node(node.val);
        copy.next = node.next;
        node.next = copy;
    }
    for (let node = head; node !== null; node = node.next.next) {
        node.next.random = node.random === null ? null : node.random.next;
    }
    const result = head.next;
    for (let node = head; node !== null; node = node.next) {
        const copy = node.next;
        node.next = copy.next;
        copy.next = node.next === null ? null : node.next.next;
    }
    return result;
}
