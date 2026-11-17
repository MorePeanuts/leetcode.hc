function findTargetSumWays(nums, target) {
    let total = 0;
    for (let i = 0; i < nums.length; ++i) {
        total += nums[i];
    }
    if (target > total || target < -total || ((total + target) & 1) !== 0) {
        return 0;
    }
    let goal = (total + target) >> 1;
    const ways = new Int32Array(goal + 1);
    ways[0] = 1;
    for (let i = 0; i < nums.length; ++i) {
        let value = nums[i];
        for (let subtotal = goal; subtotal >= value; --subtotal) {
            ways[subtotal] += ways[subtotal - value];
        }
    }
    let answer = ways[goal];
    return answer;
}
