struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next) {
        struct Node* copy = malloc(sizeof(*copy));
        *copy = (struct Node){.val = node->val, .next = node->next};
        node->next = copy;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next) {
        node->next->random = node->random == NULL ? NULL : node->random->next;
    }

    struct Node* result = head->next;
    for (struct Node* node = head; node != NULL; node = node->next) {
        struct Node* copy = node->next;
        node->next = copy->next;
        copy->next = node->next == NULL ? NULL : node->next->next;
    }
    return result;
}
