class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        vector<TreeNode *> stack;
        vector<int> depths;
        stack.push_back(root);
        depths.push_back(0);
        while (!stack.empty()) {
            TreeNode *node = stack.back();
            stack.pop_back();
            int depth = depths.back();
            depths.pop_back();
            if (depth == static_cast<int>(result.size())) {
                result.push_back(node->val);
            }
            if (node->left != nullptr) {
                stack.push_back(node->left);
                depths.push_back(depth + 1);
            }
            if (node->right != nullptr) {
                stack.push_back(node->right);
                depths.push_back(depth + 1);
            }
        }
        return result;
    }
};
