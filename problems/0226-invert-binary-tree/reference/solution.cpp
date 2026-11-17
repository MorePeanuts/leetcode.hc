class Solution {
public:
    TreeNode * invertTree(TreeNode * root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode * left = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(left);
        return root;
    }
};
