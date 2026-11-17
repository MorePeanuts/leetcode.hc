function minSubArrayLen(target: number, nums: number[]): number {
    let left = 0;
    let sum = 0;
    let best = nums.length + 1;
    for (let right = 0; right < nums.length; ++right) {
        sum += nums[right];
        while (sum >= target) {
            let size = right - left + 1;
            if (size < best) {
                best = size;
            }
            sum -= nums[left++];
        }
    }
    return best > nums.length ? 0 : best;
}
