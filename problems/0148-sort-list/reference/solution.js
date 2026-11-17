function sortList(head) {
    function splitRun(node, size) {
        if (node === null) {
            return null;
        }
        for (let i = 1; i < size && node.next !== null; i++) {
            node = node.next;
        }
        const rest = node.next;
        node.next = null;
        return rest;
    }

    let length = 0;
    let node = head;
    while (node !== null) {
        length++;
        node = node.next;
    }
    const dummy = new ListNode(0);
    let sentinel = dummy;
    sentinel.next = head;
    for (let width = 1; width < length; width *= 2) {
        let tail = sentinel;
        let current = sentinel.next;
        while (current !== null) {
            let left = current;
            let right = splitRun(left, width);
            current = splitRun(right, width);
            while (left !== null && right !== null) {
                if (left.val <= right.val) {
                    tail.next = left;
                    left = left.next;
                } else {
                    tail.next = right;
                    right = right.next;
                }
                tail = tail.next;
            }
            tail.next = left !== null ? left : right;
            while (tail.next !== null) {
                tail = tail.next;
            }
        }
    }
    return sentinel.next;
}
