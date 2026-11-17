class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (head != nullptr) {
            ListNode* end = head->next;
            while (end != nullptr && end->val == head->val) {
                end = end->next;
            }
            if (head->next == end) {
                tail->next = head;
                tail = head;
            }
            head = end;
        }
        tail->next = nullptr;
        return dummy->next;
    }
};
