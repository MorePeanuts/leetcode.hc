function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    let dummy = new ListNode(0);
    let tail = dummy;
    let carry = 0;
    while (l1 !== null || l2 !== null || carry !== 0) {
        let sum = carry;
        if (l1 !== null) {
            sum += l1.val;
            l1 = l1.next;
        }
        if (l2 !== null) {
            sum += l2.val;
            l2 = l2.next;
        }
        tail.next = new ListNode(sum % 10);
        tail = tail.next;
        carry = sum >= 10 ? 1 : 0;
    }
    return dummy.next;
}
