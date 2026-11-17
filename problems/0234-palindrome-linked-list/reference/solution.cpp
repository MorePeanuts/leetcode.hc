class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* previous = nullptr;
        while (slow != nullptr) {
            ListNode* next = slow->next;
            slow->next = previous;
            previous = slow;
            slow = next;
        }
        ListNode* left = head;
        while (previous != nullptr) {
            if (left->val != previous->val) return false;
            left = left->next;
            previous = previous->next;
        }
        return true;
    }
};
