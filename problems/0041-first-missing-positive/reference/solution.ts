function firstMissingPositive(nums: number[]): number {
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] !== nums[i]) {
            let target = nums[i] - 1;
            let value = nums[i];
            nums[i] = nums[target];
            nums[target] = value;
        }
    }
    for (let i = 0; i < n; i++) {
        if (nums[i] !== i + 1) return i + 1;
    }
    return n + 1;
}
