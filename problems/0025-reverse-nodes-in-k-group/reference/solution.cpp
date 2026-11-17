class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* before = &dummy;
        while (true) {
            ListNode* end = before;
            for (int i = 0; i < k; i++) {
                end = end->next;
                if (end == nullptr) return dummy.next;
            }
            ListNode* after = end->next;
            ListNode* previous = after;
            ListNode* current = before->next;
            while (current != after) {
                ListNode* next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            ListNode* first = before->next;
            before->next = end;
            before = first;
        }
    }
};
