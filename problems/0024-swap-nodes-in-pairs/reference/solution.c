static struct ListNode* newListNode(int val) {
    struct ListNode* node = malloc(sizeof(*node));
    *node = (struct ListNode){.val = val, .next = NULL};
    return node;
}

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy = newListNode(0);
    dummy->next = head;
    struct ListNode* prev = dummy;
    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }
    return dummy->next;
}
