int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    typedef struct {
        struct TreeNode* node;
        int depth;
    } Frame;
    Frame* stack = malloc(16 * sizeof(*stack));
    int capacity = 16;
    int size = 0;
    stack[size++] = (Frame){root, 1};
    int best = 0;
    while (size > 0) {
        struct TreeNode* node = stack[size - 1].node;
        int depth = stack[size - 1].depth;
        --size;
        if (size + 2 > capacity) {
            capacity *= 2;
            stack = realloc(stack, (size_t)capacity * sizeof(*stack));
        }
        if (depth > best) {
            best = depth;
        }
        if (node->left != NULL) {
            stack[size++] = (Frame){node->left, depth + 1};
        }
        if (node->right != NULL) {
            stack[size++] = (Frame){node->right, depth + 1};
        }
    }
    free(stack);
    return best;
}
