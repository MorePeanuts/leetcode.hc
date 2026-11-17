#include <stdbool.h>
#include <stdlib.h>

static struct TreeNode* makeNode(int val) {
    struct TreeNode* node = malloc(sizeof(*node));
    *node = (struct TreeNode){.val = val, .left = NULL, .right = NULL};
    return node;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* inserted = makeNode(val);
    if (root == NULL) return inserted;
    struct TreeNode* node = root;
    while (true) {
        if (val < node->val) {
            if (node->left == NULL) {
                node->left = inserted;
                return root;
            }
            node = node->left;
        } else {
            if (node->right == NULL) {
                node->right = inserted;
                return root;
            }
            node = node->right;
        }
    }
}
