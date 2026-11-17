void flatten(struct TreeNode* root) {
    struct TreeNode* current = root;
    while (current != NULL) {
        if (current->left != NULL) {
            struct TreeNode* predecessor = current->left;
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }
            predecessor->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}
