struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode small = {0}, large = {0};
    struct ListNode *smallTail = &small, *largeTail = &large;
    while (head != NULL) {
        if (head->val < x) {
            smallTail->next = head;
            smallTail = head;
        } else {
            largeTail->next = head;
            largeTail = head;
        }
        head = head->next;
    }
    largeTail->next = NULL;
    smallTail->next = large.next;
    return small.next;
}
