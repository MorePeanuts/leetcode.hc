#include <stdlib.h>

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(2000 * sizeof(*result));
    int* columns = malloc(2000 * sizeof(*columns));
    *returnSize = 0;
    *returnColumnSizes = columns;
    if (root == NULL) return result;
    struct TreeNode* queue[2000]; // At most 2000 nodes
    int tail = 0;
    queue[tail++] = root;
    for (int head = 0; head < tail;) {
        int limit = tail;
        int* values = malloc((size_t)(limit - head) * sizeof(*values));
        columns[*returnSize] = limit - head;
        for (int i = 0; head < limit; i++) {
            struct TreeNode* node = queue[head++];
            values[i] = node->val;
            if (node->left != NULL) queue[tail++] = node->left;
            if (node->right != NULL) queue[tail++] = node->right;
        }
        result[(*returnSize)++] = values;
    }
    return result;
}
