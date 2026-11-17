static struct ListNode *mergeTwo(struct ListNode *a, struct ListNode *b) {
    struct ListNode dummy = {0};
    struct ListNode *tail = &dummy;
    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a != NULL ? a : b;
    return dummy.next;
}

struct ListNode *mergeKLists(struct ListNode **lists, int n) {
    for (int step = 1; step < n; step *= 2) {
        for (int i = 0; i + step < n; i += 2 * step) {
            lists[i] = mergeTwo(lists[i], lists[i + step]);
        }
    }
    return n == 0 ? NULL : lists[0];
}
