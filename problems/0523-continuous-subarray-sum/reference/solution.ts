function checkSubarraySum(nums: number[], k: number): boolean {
    const first = new Map([[0, -1]]);
    let remainder = 0;
    for (let i = 0; i < nums.length; i++) {
        remainder = (remainder + nums[i]) % k;
        const previous = first.get(remainder);
        if (previous === undefined) {
            first.set(remainder, i);
        } else if (i - previous >= 2) {
            return true;
        }
    }
    return false;
}
