#include <algorithm>
#include <cstdlib>

class Solution {
    static int height(const TreeNode* node) {
        if (!node) return 0;
        int left = height(node->left);
        if (left < 0) return -1;
        int right = height(node->right);
        if (right < 0 || std::abs(left - right) > 1) return -1;
        return 1 + std::max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};
