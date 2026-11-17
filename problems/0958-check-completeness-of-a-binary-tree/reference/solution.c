bool isCompleteTree(struct TreeNode* root) {
    // At most two child slots per node, plus the root.
    struct TreeNode* queue[201];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    bool gap = false;
    while (head < tail) {
        struct TreeNode* node = queue[head++];
        if (node == NULL) {
            gap = true;
        } else {
            if (gap) {
                return false;
            }
            queue[tail++] = node->left;
            queue[tail++] = node->right;
        }
    }
    return true;
}
