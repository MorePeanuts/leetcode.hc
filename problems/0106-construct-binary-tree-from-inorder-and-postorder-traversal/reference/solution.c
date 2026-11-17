static struct TreeNode *newNode(int value) {
    struct TreeNode *node = malloc(sizeof(*node));
    *node = (struct TreeNode){.val = value};
    return node;
}

struct TreeNode *buildTree(int *inorder, int n, int *postorder, int postorderSize) {
    struct TreeNode * root = newNode(postorder[n - 1]);
    (void)postorderSize;
    struct TreeNode *stack[n];
    int size = 0;
    stack[size++] = (root);
    int index = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        struct TreeNode * node = stack[size - 1];
        struct TreeNode * child = newNode(postorder[i]);
        if (node->val != inorder[index]) {
            node->right = child;
        } else {
            while (size > 0 && stack[size - 1]->val == inorder[index]) {
                node = stack[--size];
                index--;
            }
            node->left = child;
        }
        stack[size++] = (child);
    }
    return root;
}
