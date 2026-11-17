struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* previous = NULL;
    while (head != NULL) {
        struct ListNode* next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
}
