function reverseKGroup(head, k) {
    const dummy = new ListNode(0, head);
    let before = dummy;
    while (true) {
        let end = before;
        for (let i = 0; i < k; i++) {
            end = end.next;
            if (end === null) return dummy.next;
        }
        let after = end.next;
        let previous = after;
        let current = before.next;
        while (current !== after) {
            let next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        let first = before.next;
        before.next = end;
        before = first;
    }
}
