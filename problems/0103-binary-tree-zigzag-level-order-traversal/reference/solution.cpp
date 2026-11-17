class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        vector<TreeNode *> queue;
        queue.push_back(root);
        int head = 0;
        bool forward = true;
        while (head < static_cast<int>(queue.size())) {
            int end = static_cast<int>(queue.size());
            int width = end - head;
            vector<int> row(width);
            for (int i = 0; i < width; i++) {
                TreeNode * node = queue[head++];
                row[forward ? i : width - 1 - i] = node->val;
                if (node->left != nullptr) {
                    queue.push_back(node->left);
                }
                if (node->right != nullptr) {
                    queue.push_back(node->right);
                }
            }
            result.push_back(std::move(row));
            forward = !forward;
        }
        return result;
    }
};
