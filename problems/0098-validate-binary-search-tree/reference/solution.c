#include <stdbool.h>
#include <stdlib.h>

bool isValidBST(struct TreeNode* root) {
    struct TreeNode* stack[10000];
    int count = 0;
    struct TreeNode* previous = NULL;
    struct TreeNode* node = root;
    while (node != NULL || count > 0) {
        while (node != NULL) {
            stack[count++] = node;
            node = node->left;
        }
        node = stack[--count];
        if (previous != NULL && node->val <= previous->val) return false;
        previous = node;
        node = node->right;
    }
    return true;
}
