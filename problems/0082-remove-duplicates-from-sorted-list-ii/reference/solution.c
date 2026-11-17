static struct ListNode* newListNode(int val) {
    struct ListNode* node = malloc(sizeof(*node));
    *node = (struct ListNode){.val = val, .next = NULL};
    return node;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* dummy = newListNode(0);
    struct ListNode* tail = dummy;
    while (head != NULL) {
        struct ListNode* end = head->next;
        while (end != NULL && end->val == head->val) {
            end = end->next;
        }
        if (head->next == end) {
            tail->next = head;
            tail = head;
        }
        head = end;
    }
    tail->next = NULL;
    return dummy->next;
}
