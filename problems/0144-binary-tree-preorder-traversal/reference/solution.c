int * preorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    int *result = malloc(100 * sizeof(*result));
    if (root == NULL) {
        return result;
    }
    struct TreeNode *stack[100];
    int size = 0;
    stack[size++] = (root);
    while (size > 0) {
        struct TreeNode *node = stack[--size];
        result[(*returnSize)++] = (node->val);
        if (node->right != NULL) {
            stack[size++] = (node->right);
        }
        if (node->left != NULL) {
            stack[size++] = (node->left);
        }
    }
    return result;
}
