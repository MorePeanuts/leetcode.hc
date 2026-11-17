class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* inserted = new TreeNode(val);
        if (root == nullptr) return inserted;
        TreeNode* node = root;
        while (true) {
            if (val < node->val) {
                if (node->left == nullptr) {
                    node->left = inserted;
                    return root;
                }
                node = node->left;
            } else {
                if (node->right == nullptr) {
                    node->right = inserted;
                    return root;
                }
                node = node->right;
            }
        }
    }
};
