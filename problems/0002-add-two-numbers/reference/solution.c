static struct ListNode* newListNode(int val) {
    struct ListNode* node = malloc(sizeof(*node));
    *node = (struct ListNode){.val = val, .next = NULL};
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = newListNode(0);
    struct ListNode* tail = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        tail->next = newListNode(sum % 10);
        tail = tail->next;
        carry = sum >= 10 ? 1 : 0;
    }
    return dummy->next;
}
