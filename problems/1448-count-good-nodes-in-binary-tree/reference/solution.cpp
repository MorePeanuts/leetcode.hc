class Solution {
public:
    int goodNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        vector<pair<TreeNode *, int>> stack{{root, root->val}};
        int result = 0;
        while (!stack.empty()) {
            auto [node, maximum] = stack.back();
            stack.pop_back();
            int high = maximum;
            if (node->val >= high) {
                result++;
                high = node->val;
            }
            if (node->left != nullptr) {
                stack.emplace_back(node->left, high);
            }
            if (node->right != nullptr) {
                stack.emplace_back(node->right, high);
            }
        }

        return result;
    }
};
