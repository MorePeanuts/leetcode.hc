function reverseBetween(head: ListNode | null, left: number, right: number): ListNode | null {
    const dummy = new ListNode(0);
    let before: ListNode | null = dummy;
    before.next = head;
    for (let i = 1; i < left; i++) {
        before = before.next!;
    }
    let first: ListNode | null = before.next;
    for (let i = left; i < right; i++) {
        let moved: ListNode | null = first.next;
        first.next = moved.next;
        moved.next = before.next;
        before.next = moved;
    }
    return dummy.next;
}
