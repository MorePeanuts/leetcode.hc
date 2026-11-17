static void visit(struct TreeNode* node, char* path, int end, char** result, int* size) {
    if (node == NULL) {
        return;
    }
    end += sprintf(path + end, end == 0 ? "%d" : "->%d", node->val);
    if (node->left == NULL && node->right == NULL) {
        char* copy = malloc((size_t)end + 1);
        memcpy(copy, path, (size_t)end + 1);
        result[(*size)++] = copy;
        return;
    }
    visit(node->left, path, end, result, size);
    visit(node->right, path, end, result, size);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    // At most 100 nodes with values in [-100, 100].
    char** paths = malloc(100 * sizeof(*paths));
    char path[601];
    *returnSize = 0;
    visit(root, path, 0, paths, returnSize);
    return paths;
}
