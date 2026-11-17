function pivotIndex(nums: number[]): number {
    let right = 0;
    for (let i = 0; i < nums.length; ++i) {
        right += nums[i];
    }
    let left = 0;
    for (let i = 0; i < nums.length; ++i) {
        right -= nums[i];
        if (left === right) {
            return i;
        }
        left += nums[i];
    }
    return -1;
}
