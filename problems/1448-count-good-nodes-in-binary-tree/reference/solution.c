struct Entry {
    struct TreeNode *node;
    int high;
};

int goodNodes(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    struct Entry *stack = malloc(100000 * sizeof(*stack));
    int size = 1;
    stack[0] = (struct Entry){root, root->val};
    int result = 0;
    while (size > 0) {
        struct Entry entry = stack[size - 1];
        size--;
        int high = entry.high;
        if (entry.node->val >= high) {
            result++;
            high = entry.node->val;
        }
        if (entry.node->left != NULL) {
            stack[size++] = (struct Entry){entry.node->left, high};
        }
        if (entry.node->right != NULL) {
            stack[size++] = (struct Entry){entry.node->right, high};
        }
    }
    free(stack);
    return result;
}
