struct TreeNode * convertBST(struct TreeNode *root) {
    struct TreeNode *stack[10000];
    int size = 0;
    int total = 0;
    struct TreeNode *node = root;
    while (node != NULL || size > 0) {
        while (node != NULL) {
            stack[size++] = (node);
            node = node->right;
        }
        node = stack[size - 1];
        size--;
        total += node->val;
        node->val = total;
        node = node->left;
    }
    return root;
}
