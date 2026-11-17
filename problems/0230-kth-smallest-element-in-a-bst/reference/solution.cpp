class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<TreeNode*> stack;
        TreeNode* node = root;
        while (node != nullptr || !stack.empty()) {
            while (node != nullptr) {
                stack.push_back(node);
                node = node->left;
            }
            node = stack.back();
            stack.pop_back();
            if (--k == 0) {

                return node->val;
            }
            node = node->right;
        }

        return 0;
    }
};
