function canPartition(nums) {
    let total = 0;
    for (let i = 0; i < nums.length; i++) total += nums[i];
    if (total % 2 !== 0) return false;
    let target = total / 2;
    const possible = new Uint8Array(target + 1);
    possible[0] = 1;
    for (let i = 0; i < nums.length; i++) {
        let value = nums[i];
        for (let subtotal = target; subtotal >= value; subtotal--) {
            if (possible[subtotal - value]) possible[subtotal] = 1;
        }
    }
    return possible[target] === 1;
}
