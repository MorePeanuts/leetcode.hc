class Solution {
public:
    int sumFrom(TreeNode* node, int prefix) {
        if (node == nullptr) {
            return 0;
        }
        int value = prefix * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return value;
        }
        return sumFrom(node->left, value) + sumFrom(node->right, value);
    }

    int sumNumbers(TreeNode* root) {
        return sumFrom(root, 0);
    }
};
