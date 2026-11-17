struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode* parent = NULL;
    struct TreeNode* node = root;
    while (node != NULL && node->val != key) {
        parent = node;
        node = key < node->val ? node->left : node->right;
    }
    if (node == NULL) {
        return root;
    }
    if (node->left != NULL && node->right != NULL) {
        struct TreeNode* successorParent = node;
        struct TreeNode* successor = node->right;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        node->val = successor->val;
        parent = successorParent;
        node = successor;
    }
    struct TreeNode* child = node->left != NULL ? node->left : node->right;
    if (parent == NULL) {
        return child;
    }
    if (parent->left == node) {
        parent->left = child;
    } else {
        parent->right = child;
    }
    return root;
}
