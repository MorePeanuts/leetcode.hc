int minDepth(struct TreeNode * root) {
    if (root == NULL) {
        return 0;
    }
    size_t capacity = 16;
    struct TreeNode **queue = malloc(capacity * sizeof(*queue));
    size_t head = 0;
    size_t tail = 1;
    queue[0] = root;
    int depth = 1;
    while (head < tail) {
        size_t end = tail;
        while (head < end) {
            struct TreeNode *node = queue[head++];
            if (node->left == NULL && node->right == NULL) {
                free(queue);
                return depth;
            }
            if (capacity - tail < 2) {
                capacity *= 2;
                queue = realloc(queue, capacity * sizeof(*queue));
            }
            if (node->left != NULL) {
                queue[tail++] = node->left;
            }
            if (node->right != NULL) {
                queue[tail++] = node->right;
            }
        }
        depth++;
    }
    free(queue);
    return 0;
}
