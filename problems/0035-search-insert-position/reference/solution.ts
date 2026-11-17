function searchInsert(nums: number[], target: number): number {
    let left = 0;
    let right = nums.length;
    while (left < right) {
        let mid = left + ((right - left) >> 1);
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
