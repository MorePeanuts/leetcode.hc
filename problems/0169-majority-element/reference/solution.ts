function majorityElement(nums: number[]): number {
    const n = nums.length;
    let candidate = 0;
    let count = 0;
    for (let i = 0; i < n; i++) {
        if (count === 0) {
            candidate = nums[i];
        }
        count += nums[i] === candidate ? 1 : -1;
    }
    return candidate;
}
