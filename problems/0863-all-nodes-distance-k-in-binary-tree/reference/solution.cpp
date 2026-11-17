class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* parents[501] = {}, *queue[500];
        bool seen[501] = {};
        queue[0] = root;
        int tail = 1;
        for (int head = 0; head < tail; head++) {
            TreeNode* node = queue[head];
            if (node->left != nullptr) {
                parents[node->left->val] = node;
                queue[tail++] = node->left;
            }
            if (node->right != nullptr) {
                parents[node->right->val] = node;
                queue[tail++] = node->right;
            }
        }
        queue[0] = target;
        seen[target->val] = true;
        tail = 1;
        int head = 0;
        for (int depth = 0; depth < k && head < tail; depth++) {
            int levelEnd = tail;
            for (; head < levelEnd; head++) {
                TreeNode* node = queue[head];
                TreeNode* neighbors[] = {node->left, node->right, parents[node->val]};
                for (TreeNode* neighbor : neighbors) {

                    if (neighbor != nullptr && !seen[neighbor->val]) {
                        seen[neighbor->val] = true;
                        queue[tail++] = neighbor;
                    }
                }
            }
        }
        vector<int> result;
            for (int i = head; i < tail; i++) result.push_back(queue[i]->val);
            return result;
    }
};
