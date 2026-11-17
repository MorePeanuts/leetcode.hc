function reverseList(head: ListNode | null): ListNode | null {
    let previous = null;
    while (head !== null) {
        let next = head.next;
        head.next = previous;
        previous = head;
        head = next;
    }
    return previous;
}
