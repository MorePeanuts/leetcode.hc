struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* node = head;
    while (node && node->next) {
        if (node->val == node->next->val) {
            node->next = node->next->next;
        } else {
            node = node->next;
        }
    }
    return head;
}
