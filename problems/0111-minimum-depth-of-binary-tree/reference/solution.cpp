class Solution {
public:
    int minDepth(TreeNode * root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> frontier;
        frontier.push(root);
        int depth = 1;
        while (!frontier.empty()) {
            int width = frontier.size();
            for (int i = 0; i < width; i++) {
                TreeNode *node = frontier.front();
                frontier.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                if (node->left != nullptr) {
                    frontier.push(node->left);
                }
                if (node->right != nullptr) {
                    frontier.push(node->right);
                }
            }
            depth++;
        }
        return 0;
    }
};
