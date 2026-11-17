function rob(nums: number[]): number {
    function robRange(left: number, right: number) {
        let previous = 0;
        let current = 0;
        for (let i = left; i < right; i++) {
            let take = previous + nums[i];
            previous = current;
            if (take > current) current = take;
        }
        return current;
    }

    let n = nums.length;
    if (n === 1) return nums[0];
    let left = robRange(0, n - 1);
    let right = robRange(1, n);
    return left > right ? left : right;
}
