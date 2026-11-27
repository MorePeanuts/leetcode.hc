function permuteUnique(nums) {
    const result = [];
    function visit(start) {
        if (start === nums.length) {
            result.push(nums.slice());
            return;
        }
        const used = new Set();
        for (let i = start; i < nums.length; i++) {
            if (used.has(nums[i])) {
                continue;
            }
            used.add(nums[i]);
            const value = nums[start];
            nums[start] = nums[i];
            nums[i] = value;
            visit(start + 1);
            nums[i] = nums[start];
            nums[start] = value;
        }
    }
    visit(0);
    return result;
}
