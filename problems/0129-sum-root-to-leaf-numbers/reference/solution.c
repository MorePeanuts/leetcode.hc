static int sumFrom(struct TreeNode* node, int prefix) {
    if (node == NULL) {
        return 0;
    }
    int value = prefix * 10 + node->val;
    if (node->left == NULL && node->right == NULL) {
        return value;
    }
    return sumFrom(node->left, value) + sumFrom(node->right, value);
}

int sumNumbers(struct TreeNode* root) {
    return sumFrom(root, 0);
}
