function sortedArrayToBST(nums: number[]): TreeNode | null {
    function build(left: number, right: number): TreeNode | null {
        if (left === right) {
            return null;
        }
        const mid = left + ((right - left) >> 1);
        const node = new TreeNode(nums[mid]);
        node.left = build(left, mid);
        node.right = build(mid + 1, right);
        return node;
    }
    return build(0, nums.length);
}
