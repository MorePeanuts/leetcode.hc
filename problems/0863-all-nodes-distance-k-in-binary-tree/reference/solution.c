#include <stdbool.h>
#include <stdlib.h>

int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
    struct TreeNode* parents[501] = {0}, *queue[500];
    bool seen[501] = {0};
    queue[0] = root;
    int tail = 1;
    for (int head = 0; head < tail; head++) {
        struct TreeNode* node = queue[head];
        if (node->left != NULL) {
            parents[node->left->val] = node;
            queue[tail++] = node->left;
        }
        if (node->right != NULL) {
            parents[node->right->val] = node;
            queue[tail++] = node->right;
        }
    }
    queue[0] = target;
    seen[target->val] = true;
    tail = 1;
    int head = 0;
    for (int depth = 0; depth < k && head < tail; depth++) {
        int levelEnd = tail;
        for (; head < levelEnd; head++) {
            struct TreeNode* node = queue[head];
            struct TreeNode* neighbors[] = {node->left, node->right, parents[node->val]};
            for (int i = 0; i < 3; i++) {
                struct TreeNode* neighbor = neighbors[i];
                if (neighbor != NULL && !seen[neighbor->val]) {
                    seen[neighbor->val] = true;
                    queue[tail++] = neighbor;
                }
            }
        }
    }
    *returnSize = tail - head;
    int* result = malloc((size_t)*returnSize * sizeof(*result));
    for (int i = head; i < tail; i++) result[i - head] = queue[i]->val;
    return result;
}
