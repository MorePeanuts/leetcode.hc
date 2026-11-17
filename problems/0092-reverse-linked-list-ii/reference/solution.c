struct ListNode * reverseBetween(struct ListNode * head, int left, int right) {
    struct ListNode dummy = {0};
    struct ListNode * before = &dummy;
    before->next = head;
    for (int i = 1; i < left; i++) {
        before = before->next;
    }
    struct ListNode * first = before->next;
    for (int i = left; i < right; i++) {
        struct ListNode * moved = first->next;
        first->next = moved->next;
        moved->next = before->next;
        before->next = moved;
    }
    return dummy.next;
}
