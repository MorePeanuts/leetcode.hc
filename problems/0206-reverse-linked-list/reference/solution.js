function reverseList(head) {
    let previous = null;
    while (head !== null) {
        let next = head.next;
        head.next = previous;
        previous = head;
        head = next;
    }
    return previous;
}
