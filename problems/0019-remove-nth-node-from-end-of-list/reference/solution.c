#include <stdbool.h>
#include <stddef.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy = {.val = 0, .next = head};
    struct ListNode* lead = &dummy;
    struct ListNode* trail = &dummy;
    for (int i = 0; i < n; i++) lead = lead->next;
    while (lead->next) {
        lead = lead->next;
        trail = trail->next;
    }
    trail->next = trail->next->next;
    return dummy.next;
}
