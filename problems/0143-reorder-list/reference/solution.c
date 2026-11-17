#include <stddef.h>

void reorderList(struct ListNode* head) {
    if (head == NULL) return;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* second = slow->next;
    slow->next = NULL;
    struct ListNode* previous = NULL;
    while (second != NULL) {
        struct ListNode* next = second->next;
        second->next = previous;
        previous = second;
        second = next;
    }
    struct ListNode* first = head;
    while (previous != NULL) {
        struct ListNode* firstNext = first->next;
        struct ListNode* secondNext = previous->next;
        first->next = previous;
        previous->next = firstNext;
        first = firstNext;
        previous = secondNext;
    }
}
