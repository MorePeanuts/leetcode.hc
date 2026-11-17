#include <vector>

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        std::vector<TreeNode*> stack(preorder.size());
        stack[0] = root;
        int count = 1;
        int j = 0;
        for (int i = 1; i < static_cast<int>(preorder.size()); i++) {
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* parent = stack[count - 1];
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
};
