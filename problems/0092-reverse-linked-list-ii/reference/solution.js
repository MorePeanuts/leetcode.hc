function reverseBetween(head, left, right) {
    const dummy = new ListNode(0);
    let before = dummy;
    before.next = head;
    for (let i = 1; i < left; i++) {
        before = before.next;
    }
    let first = before.next;
    for (let i = left; i < right; i++) {
        let moved = first.next;
        first.next = moved.next;
        moved.next = before.next;
        before.next = moved;
    }
    return dummy.next;
}
