struct Node * connect(struct Node * root) {
    struct Node * level = root;
    while (level != NULL) {
        struct Node dummy = {0};
        struct Node * tail = &dummy;
        struct Node * node = level;
        while (node != NULL) {
            if (node->left != NULL) {
                tail->next = node->left;
                tail = tail->next;
            }
            if (node->right != NULL) {
                tail->next = node->right;
                tail = tail->next;
            }
            node = node->next;
        }
        level = dummy.next;
    }
    return root;
}
