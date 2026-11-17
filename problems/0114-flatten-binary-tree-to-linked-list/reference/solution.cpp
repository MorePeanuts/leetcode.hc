class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->left != nullptr) {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }
};
