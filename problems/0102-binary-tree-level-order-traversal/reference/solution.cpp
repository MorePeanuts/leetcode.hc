#include <utility>
#include <vector>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        vector<TreeNode*> queue;
        queue.push_back(root);
        for (int head = 0; head < static_cast<int>(queue.size());) {
            int limit = static_cast<int>(queue.size());
            vector<int> values;
            for (int i = 0; head < limit; i++) {
                TreeNode* node = queue[head++];
                values.push_back(node->val);
                if (node->left != nullptr) queue.push_back(node->left);
                if (node->right != nullptr) queue.push_back(node->right);
            }
            result.push_back(std::move(values));
        }
        return result;
    }
};
