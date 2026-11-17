static void visit(struct TreeNode* node, int* result, int* size) {
    if (node == NULL) {
        return;
    }
    visit(node->left, result, size);
    visit(node->right, result, size);
    result[(*size)++] = node->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    // The statement bounds the tree at 100 nodes.
    int* result = malloc(100 * sizeof(*result));
    *returnSize = 0;
    visit(root, result, returnSize);
    return result;
}
