static struct ListNode * splitRun(struct ListNode * node, int size) {
    if (node == NULL) {
        return NULL;
    }
    for (int i = 1; i < size && node->next != NULL; i++) {
        node = node->next;
    }
    struct ListNode * rest = node->next;
    node->next = NULL;
    return rest;
}

struct ListNode * sortList(struct ListNode * head) {
    int length = 0;
    struct ListNode * node = head;
    while (node != NULL) {
        length++;
        node = node->next;
    }
    struct ListNode dummy = {0};
    struct ListNode * sentinel = &dummy;
    sentinel->next = head;
    for (int width = 1; width < length; width *= 2) {
        struct ListNode * tail = sentinel;
        struct ListNode * current = sentinel->next;
        while (current != NULL) {
            struct ListNode * left = current;
            struct ListNode * right = splitRun(left, width);
            current = splitRun(right, width);
            while (left != NULL && right != NULL) {
                if (left->val <= right->val) {
                    tail->next = left;
                    left = left->next;
                } else {
                    tail->next = right;
                    right = right->next;
                }
                tail = tail->next;
            }
            tail->next = left != NULL ? left : right;
            while (tail->next != NULL) {
                tail = tail->next;
            }
        }
    }
    return sentinel->next;
}
