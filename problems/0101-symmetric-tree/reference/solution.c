static bool mirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL || right == NULL) {
        return left == right;
    }
    return left->val == right->val
        && mirror(left->left, right->right)
        && mirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    return root == NULL || mirror(root->left, root->right);
}
