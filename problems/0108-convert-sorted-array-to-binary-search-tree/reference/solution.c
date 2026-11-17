static struct TreeNode* build(const int* nums, int left, int right) {
    if (left == right) {
        return NULL;
    }
    int mid = left + (right - left) / 2;
    struct TreeNode* node = malloc(sizeof(*node));
    node->val = nums[mid];
    node->left = build(nums, left, mid);
    node->right = build(nums, mid + 1, right);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return build(nums, 0, numsSize);
}
