class Solution {
public:
    bool sameTree(TreeNode* first, TreeNode* second) {
        if (first == nullptr || second == nullptr) {
            return first == second;
        }
        return first->val == second->val
            && sameTree(first->left, second->left)
            && sameTree(first->right, second->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return subRoot == nullptr;
        }
        return sameTree(root, subRoot)
            || isSubtree(root->left, subRoot)
            || isSubtree(root->right, subRoot);
    }
};
