struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int first[100], second[100];
    int a = 0;
    int b = 0;
    for (struct ListNode * node = l1; node != NULL; node = node->next) {
        first[a++] = node->val;
    }
    for (struct ListNode * node = l2; node != NULL; node = node->next) {
        second[b++] = node->val;
    }
    int carry = 0;
    struct ListNode * result = NULL;
    while (a > 0 || b > 0 || carry != 0) {
        int sum = carry;
        if (a > 0) {
            sum += first[--a];
        }
        if (b > 0) {
            sum += second[--b];
        }
        carry = sum / 10;
        struct ListNode *node = malloc(sizeof(*node));
        *node = (struct ListNode){sum % 10, result};
        result = node;
    }
    return result;
}
