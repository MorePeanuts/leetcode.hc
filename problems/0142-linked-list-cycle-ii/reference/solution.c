struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (head != slow) {
                head = head->next;
                slow = slow->next;
            }
            return head;
        }
    }
    return NULL;
}
