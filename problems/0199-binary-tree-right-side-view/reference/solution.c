int * rightSideView(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    int *result = malloc(100 * sizeof(*result));
    if (root == NULL) {
        return result;
    }
    struct TreeNode *stack[100];
    int size = 0;
    int depths[100];
    stack[size++] = (root);
    depths[size - 1] = (0);
    while (size > 0) {
        struct TreeNode *node = stack[--size];
        int depth = depths[size];
        if (depth == *returnSize) {
            result[(*returnSize)++] = (node->val);
        }
        if (node->left != NULL) {
            stack[size++] = (node->left);
            depths[size - 1] = (depth + 1);
        }
        if (node->right != NULL) {
            stack[size++] = (node->right);
            depths[size - 1] = (depth + 1);
        }
    }
    return result;
}
