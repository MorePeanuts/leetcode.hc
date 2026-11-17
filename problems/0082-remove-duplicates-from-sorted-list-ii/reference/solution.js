function deleteDuplicates(head) {
    let dummy = new ListNode(0);
    let tail = dummy;
    while (head !== null) {
        let end = head.next;
        while (end !== null && end.val === head.val) {
            end = end.next;
        }
        if (head.next === end) {
            tail.next = head;
            tail = head;
        }
        head = end;
    }
    tail.next = null;
    return dummy.next;
}
