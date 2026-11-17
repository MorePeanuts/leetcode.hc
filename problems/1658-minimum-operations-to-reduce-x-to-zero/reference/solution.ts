function minOperations(nums: number[], x: number): number {
    let keep = -x;
    for (let i = 0; i < nums.length; ++i) {
        keep += nums[i];
    }
    if (keep < 0) {
        return -1;
    }
    let left = 0;
    let sum = 0;
    let best = keep === 0 ? 0 : -1;
    for (let right = 0; right < nums.length; ++right) {
        sum += nums[right];
        while (sum > keep) {
            sum -= nums[left++];
        }
        if (sum === keep && right - left + 1 > best) {
            best = right - left + 1;
        }
    }
    return best < 0 ? -1 : nums.length - best;
}
