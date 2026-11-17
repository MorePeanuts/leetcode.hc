int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int **result = malloc(2000 * sizeof(*result));
    *returnColumnSizes = malloc(2000 * sizeof(**returnColumnSizes));
    if (root == NULL) {
        return result;
    }
    struct TreeNode *queue[2000];
    int tail = 0;
    queue[tail++] = (root);
    int head = 0;
    int tailLevel = 0;
    bool forward = true;
    while (head < tail) {
        int end = tail;
        int width = end - head;
        int *row = malloc(width * sizeof(*row));
        for (int i = 0; i < width; i++) {
            struct TreeNode * node = queue[head++];
            row[forward ? i : width - 1 - i] = node->val;
            if (node->left != NULL) {
                queue[tail++] = (node->left);
            }
            if (node->right != NULL) {
                queue[tail++] = (node->right);
            }
        }
        result[tailLevel] = row;
        (*returnColumnSizes)[tailLevel++] = width;
        *returnSize = tailLevel;
        forward = !forward;
    }
    return result;
}
