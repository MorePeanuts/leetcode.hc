function combinationSum(nums, target) {
    const result = [];
    const path = [];
    nums.sort((a, b) => a - b);
    function visit(start, remaining) {
        if (remaining === 0) {
            result.push(path.slice());
            return;
        }
        for (let i = start; i < nums.length; i++) {
            const value = nums[i];
            if (value > remaining) {
                break;
            }
            path.push(value);
            visit(i, remaining - value);
            path.pop();
        }
    }
    visit(0, target);
    return result;
}
