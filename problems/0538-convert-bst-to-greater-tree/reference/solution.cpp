class Solution {
public:
    TreeNode * convertBST(TreeNode *root) {
        vector<TreeNode *> stack;
        int total = 0;
        TreeNode *node = root;
        while (node != nullptr || !stack.empty()) {
            while (node != nullptr) {
                stack.push_back(node);
                node = node->right;
            }
            node = stack.back();
            stack.pop_back();
            total += node->val;
            node->val = total;
            node = node->left;
        }
        return root;
    }
};
