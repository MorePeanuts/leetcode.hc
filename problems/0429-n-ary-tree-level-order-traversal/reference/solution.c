#include <stdlib.h>

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (!root) return NULL;
    struct Node** queue = malloc(10000 * sizeof(*queue));
    int** result = malloc(1001 * sizeof(*result));
    int* columns = malloc(1001 * sizeof(*columns));
    *returnColumnSizes = columns;
    queue[0] = root;
    int tail = 1;
    for (int head = 0; head < tail;) {
        int end = tail;
        int width = end - head;
        int* values = malloc((size_t)width * sizeof(*values));
        for (int i = 0; head < end; i++) {
            struct Node* node = queue[head++];
            values[i] = node->val;
            for (int j = 0; j < node->numChildren; j++)
                queue[tail++] = node->children[j];
        }
        columns[*returnSize] = width;
        result[(*returnSize)++] = values;
    }
    free(queue);
    return result;
}
