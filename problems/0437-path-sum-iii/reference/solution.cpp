class Solution {
    int visit(TreeNode* node, long long sum, int target,
              std::unordered_map<long long, int>& prefixes) {
        if (node == nullptr) {
            return 0;
        }
        sum += node->val;
        auto previous = prefixes.find(sum - target);
        int count = previous == prefixes.end() ? 0 : previous->second;
        ++prefixes[sum];
        count += visit(node->left, sum, target, prefixes);
        count += visit(node->right, sum, target, prefixes);
        if (--prefixes[sum] == 0) {
            prefixes.erase(sum);
        }
        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<long long, int> prefixes{{0, 1}};
        return visit(root, 0, targetSum, prefixes);
    }
};
