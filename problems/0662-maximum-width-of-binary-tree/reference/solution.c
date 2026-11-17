struct Entry {
    struct TreeNode *node;
    long long index;
};

int widthOfBinaryTree(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    struct Entry queue[3000] = {{root, 0}};
    int tail = 1;
    int head = 0;
    int best = 0;
    while (head < tail) {
        int end = tail;
        long long base = queue[head].index;
        int width = (int)(queue[end - 1].index - base + 1);
        if (width > best) {
            best = width;
        }
        while (head < end) {
            struct TreeNode * node = queue[head].node;
            long long index = queue[head].index - base;
            head++;
            if (node->left != NULL) {
                queue[tail++] = (struct Entry){node->left, 2 * index};
            }
            if (node->right != NULL) {
                queue[tail++] = (struct Entry){node->right, 2 * index + 1};
            }
        }
    }
    return best;
}
