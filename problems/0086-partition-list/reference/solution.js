function partition(head, x) {
    const small = new ListNode(), large = new ListNode();
    let smallTail = small, largeTail = large;
    while (head != null) {
        if (head.val < x) {
            smallTail.next = head;
            smallTail = head;
        } else {
            largeTail.next = head;
            largeTail = head;
        }
        head = head.next;
    }
    largeTail.next = null;
    smallTail.next = large.next;
    return small.next;
}
