#include <vector>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::vector<TreeNode*> stack;
        TreeNode* previous = nullptr;
        TreeNode* node = root;
        while (node != nullptr || !stack.empty()) {
            while (node != nullptr) {
                stack.push_back(node);
                node = node->left;
            }
            node = stack.back();
            stack.pop_back();
            if (previous != nullptr && node->val <= previous->val) return false;
            previous = node;
            node = node->right;
        }
        return true;
    }
};
