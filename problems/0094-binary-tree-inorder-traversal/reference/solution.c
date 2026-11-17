#include <stdbool.h>
#include <stdlib.h>

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode* stack[100];
    int count = 0;
    int* result = malloc(100 * sizeof(*result));
    *returnSize = 0;
    struct TreeNode* node = root;
    while (node != NULL || count > 0) {
        while (node != NULL) {
            stack[count++] = node;
            node = node->left;
        }
        node = stack[--count];
        result[(*returnSize)++] = node->val;
        node = node->right;
    }
    return result;
}
