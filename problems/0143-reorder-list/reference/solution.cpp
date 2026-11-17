class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* previous = nullptr;
        while (second != nullptr) {
            ListNode* next = second->next;
            second->next = previous;
            previous = second;
            second = next;
        }
        ListNode* first = head;
        while (previous != nullptr) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = previous->next;
            first->next = previous;
            previous->next = firstNext;
            first = firstNext;
            previous = secondNext;
        }
    }
};
