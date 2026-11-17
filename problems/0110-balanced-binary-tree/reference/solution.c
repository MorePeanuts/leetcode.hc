#include <stdbool.h>
#include <stdlib.h>

static int height(const struct TreeNode* node) {
    if (!node) return 0;
    int left = height(node->left);
    if (left < 0) return -1;
    int right = height(node->right);
    if (right < 0 || abs(left - right) > 1) return -1;
    return 1 + (left > right ? left : right);
}

bool isBalanced(struct TreeNode* root) {
    return height(root) >= 0;
}
