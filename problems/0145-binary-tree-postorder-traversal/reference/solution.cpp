class Solution {
    void visit(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        visit(node->left, result);
        visit(node->right, result);
        result.push_back(node->val);
    }

public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        visit(root, result);
        return result;
    }
};
