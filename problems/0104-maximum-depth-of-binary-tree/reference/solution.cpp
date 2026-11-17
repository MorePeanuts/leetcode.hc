class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::vector<std::pair<TreeNode*, int>> stack;
        stack.emplace_back(root, 1);
        int best = 0;
        while (!stack.empty()) {
            TreeNode* node = stack.back().first;
            int depth = stack.back().second;
            stack.pop_back();
            if (depth > best) {
                best = depth;
            }
            if (node->left != nullptr) {
                stack.emplace_back(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                stack.emplace_back(node->right, depth + 1);
            }
        }

        return best;
    }
};
