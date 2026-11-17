function reorderList(head: ListNode | null): void {
    if (head === null) return;
    let slow = head;
    let fast = head;
    while (fast.next !== null && fast.next.next !== null) {
        slow = slow.next!;
        fast = fast.next.next;
    }
    let second = slow.next;
    slow.next = null;
    let previous: ListNode | null = null;
    while (second !== null) {
        const next = second.next;
        second.next = previous;
        previous = second;
        second = next;
    }
    let first: ListNode | null = head;
    while (previous !== null) {
        const firstNext: ListNode | null = first!.next;
        const secondNext = previous.next;
        first!.next = previous;
        previous.next = firstNext;
        first = firstNext;
        previous = secondNext;
    }
}
