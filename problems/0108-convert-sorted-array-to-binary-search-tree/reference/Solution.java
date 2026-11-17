class Solution {
    private TreeNode build(int[] nums, int left, int right) {
        if (left == right) {
            return null;
        }
        int mid = left + (right - left) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = build(nums, left, mid);
        node.right = build(nums, mid + 1, right);
        return node;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        return build(nums, 0, nums.length);
    }
}
