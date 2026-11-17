class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        std::vector<TreeNode*> queue;
        queue.push_back(root);
        size_t head = 0;
        bool gap = false;
        while (head < queue.size()) {
            TreeNode* node = queue[head++];
            if (node == nullptr) {
                gap = true;
            } else {
                if (gap) {
                    return false;
                }
                queue.push_back(node->left);
                queue.push_back(node->right);
            }
        }
        return true;
    }
};
