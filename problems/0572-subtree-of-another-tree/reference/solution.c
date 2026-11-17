static bool sameTree(struct TreeNode* first, struct TreeNode* second) {
    if (first == NULL || second == NULL) {
        return first == second;
    }
    return first->val == second->val
        && sameTree(first->left, second->left)
        && sameTree(first->right, second->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL) {
        return subRoot == NULL;
    }
    return sameTree(root, subRoot)
        || isSubtree(root->left, subRoot)
        || isSubtree(root->right, subRoot);
}
