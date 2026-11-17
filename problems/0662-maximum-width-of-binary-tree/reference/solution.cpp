class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        vector<pair<TreeNode *, long long>> queue{{root, 0}};
        int head = 0;
        int best = 0;
        while (head < static_cast<int>(queue.size())) {
            int end = static_cast<int>(queue.size());
            long long base = queue[head].second;
            int width = static_cast<int>(queue[end - 1].second - base + 1);
            if (width > best) {
                best = width;
            }
            while (head < end) {
                TreeNode * node = queue[head].first;
                long long index = queue[head].second - base;
                head++;
                if (node->left != nullptr) {
                    queue.emplace_back(node->left, 2 * index);
                }
                if (node->right != nullptr) {
                    queue.emplace_back(node->right, 2 * index + 1);
                }
            }
        }
        return best;
    }
};
