class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* node = root;
        while (node != nullptr && node->val != key) {
            parent = node;
            node = key < node->val ? node->left : node->right;
        }
        if (node == nullptr) {
            return root;
        }
        if (node->left != nullptr && node->right != nullptr) {
            TreeNode* successorParent = node;
            TreeNode* successor = node->right;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            node->val = successor->val;
            parent = successorParent;
            node = successor;
        }
        TreeNode* child = node->left != nullptr ? node->left : node->right;
        if (parent == nullptr) {
            return child;
        }
        if (parent->left == node) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        return root;
    }
};
