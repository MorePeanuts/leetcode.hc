int * postorder(struct Node *root, int *returnSize) {
    *returnSize = 0;
    int *result = malloc(10000 * sizeof(*result));
    if (root == NULL) {
        return result;
    }
    struct Node *stack[10000];
    int size = 0;
    stack[size++] = (root);
    while (size > 0) {
        struct Node *node = stack[--size];
        result[(*returnSize)++] = (node->val);
        for (int i = 0; i < node->numChildren; i++) {
            stack[size++] = node->children[i];
        }
    }
    for (int i = 0, j = *returnSize - 1; i < j; i++, j--) {
        int value = result[i];
        result[i] = result[j];
        result[j] = value;
    }
    return result;
}
