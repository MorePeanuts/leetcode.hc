#include <stdlib.h>

static struct TreeNode* makeNode(int val) {
    struct TreeNode* node = malloc(sizeof(*node));
    *node = (struct TreeNode){.val = val, .left = NULL, .right = NULL};
    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct TreeNode* root = makeNode(preorder[0]);
    struct TreeNode* stack[3000]; // preorderSize <= 3000
    stack[0] = root;
    int count = 1;
    int j = 0;
    for (int i = 1; i < preorderSize; i++) {
        struct TreeNode* node = makeNode(preorder[i]);
        struct TreeNode* parent = stack[count - 1];
        if (parent->val != inorder[j]) {
            parent->left = node;
        } else {
            while (count > 0 && stack[count - 1]->val == inorder[j]) {
                parent = stack[--count];
                j++;
            }
            parent->right = node;
        }
        stack[count++] = node;
    }
    return root;
}
