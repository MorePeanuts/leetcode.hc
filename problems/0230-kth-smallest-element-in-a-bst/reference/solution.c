int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode** stack = malloc(10000 * sizeof(*stack));
    int size = 0;
    struct TreeNode* node = root;
    while (node != NULL || size > 0) {
        while (node != NULL) {
            stack[size++] = node;
            node = node->left;
        }
        node = stack[size - 1];
        --size;
        if (--k == 0) {
            free(stack);
            return node->val;
        }
        node = node->right;
    }
    free(stack);
    return 0;
}
