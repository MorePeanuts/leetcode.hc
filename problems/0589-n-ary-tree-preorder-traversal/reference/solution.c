#include <stdlib.h>

int* preorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;
    struct Node** stack = malloc(10000 * sizeof(*stack)); // At most 10000 nodes.
    int* result = malloc(10000 * sizeof(*result));
    stack[0] = root;
    int size = 1;
    while (size > 0) {
        struct Node* node = stack[--size];
        result[(*returnSize)++] = node->val;
        for (int i = node->numChildren - 1; i >= 0; i--) stack[size++] = node->children[i];
    }
    free(stack);
    return result;
}
