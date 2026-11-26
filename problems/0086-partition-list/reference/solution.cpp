class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode small, large;
        ListNode *smallTail = &small, *largeTail = &large;
        while (head != nullptr) {
            if (head->val < x) {
                smallTail->next = head;
                smallTail = head;
            } else {
                largeTail->next = head;
                largeTail = head;
            }
            head = head->next;
        }
        largeTail->next = nullptr;
        smallTail->next = large.next;
        return small.next;
    }
};
