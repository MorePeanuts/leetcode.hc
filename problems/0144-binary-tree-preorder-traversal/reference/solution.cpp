class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        vector<TreeNode *> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode *node = stack.back();
            stack.pop_back();
            result.push_back(node->val);
            if (node->right != nullptr) {
                stack.push_back(node->right);
            }
            if (node->left != nullptr) {
                stack.push_back(node->left);
            }
        }
        return result;
    }
};
