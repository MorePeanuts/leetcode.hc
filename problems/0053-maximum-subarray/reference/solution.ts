function maxSubArray(nums: number[]): number {
    let current = nums[0];
    let best = current;
    for (let i = 1; i < nums.length; i++) {
        current = current > 0 ? current + nums[i] : nums[i];
        if (current > best) best = current;
    }
    return best;
}
