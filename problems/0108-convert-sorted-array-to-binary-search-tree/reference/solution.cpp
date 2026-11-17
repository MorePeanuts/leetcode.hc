class Solution {
    TreeNode* build(const std::vector<int>& nums, int left, int right) {
        if (left == right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        auto* node = new TreeNode(nums[mid]);
        node->left = build(nums, left, mid);
        node->right = build(nums, mid + 1, right);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return build(nums, 0, static_cast<int>(nums.size()));
    }
};
