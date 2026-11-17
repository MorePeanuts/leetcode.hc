function sortList(head: ListNode | null): ListNode | null {
    function splitRun(node: ListNode | null, size: number): ListNode | null {
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
    let node: ListNode | null = head;
    while (node !== null) {
        length++;
        node = node.next;
    }
    const dummy = new ListNode(0);
    let sentinel: ListNode | null = dummy;
    sentinel.next = head;
    for (let width = 1; width < length; width *= 2) {
        let tail: ListNode | null = sentinel;
        let current: ListNode | null = sentinel.next;
        while (current !== null) {
            let left: ListNode | null = current;
            let right: ListNode | null = splitRun(left, width);
            current = splitRun(right, width);
            while (left !== null && right !== null) {
                if (left.val <= right.val) {
                    tail.next = left;
                    left = left.next;
                } else {
                    tail.next = right;
                    right = right.next;
                }
                tail = tail.next!;
            }
            tail.next = left !== null ? left : right;
            while (tail.next !== null) {
                tail = tail.next!;
            }
        }
    }
    return sentinel.next;
}
