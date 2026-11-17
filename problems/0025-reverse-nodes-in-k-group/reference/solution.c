#include <stdbool.h>
#include <stddef.h>

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy = {.val = 0, .next = head};
    struct ListNode* before = &dummy;
    while (true) {
        struct ListNode* end = before;
        for (int i = 0; i < k; i++) {
            end = end->next;
            if (end == NULL) return dummy.next;
        }
        struct ListNode* after = end->next;
        struct ListNode* previous = after;
        struct ListNode* current = before->next;
        while (current != after) {
            struct ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        struct ListNode* first = before->next;
        before->next = end;
        before = first;
    }
}
