#include <vector>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<TreeNode*> stack;
        std::vector<int> result;
        TreeNode* node = root;
        while (node != nullptr || !stack.empty()) {
            while (node != nullptr) {
                stack.push_back(node);
                node = node->left;
            }
            node = stack.back();
            stack.pop_back();
            result.push_back(node->val);
            node = node->right;
        }
        return result;
    }
};
