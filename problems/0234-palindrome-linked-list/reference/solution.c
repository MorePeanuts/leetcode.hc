#include <stdbool.h>
#include <stddef.h>

bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* previous = NULL;
    while (slow != NULL) {
        struct ListNode* next = slow->next;
        slow->next = previous;
        previous = slow;
        slow = next;
    }
    struct ListNode* left = head;
    while (previous != NULL) {
        if (left->val != previous->val) return false;
        left = left->next;
        previous = previous->next;
    }
    return true;
}
