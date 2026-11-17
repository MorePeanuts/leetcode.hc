function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    const dummy = new ListNode(0, head);
    let before = dummy;
    while (true) {
        let end: ListNode | null = before;
        for (let i = 0; i < k; i++) {
            end = end!.next;
            if (end === null) return dummy.next;
        }
        let after = end.next;
        let previous = after;
        let current = before.next;
        while (current !== after) {
            const next: ListNode | null = current!.next;
            current!.next = previous;
            previous = current;
            current = next;
        }
        const first = before.next!;
        before.next = end;
        before = first;
    }
}
