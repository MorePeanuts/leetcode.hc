function subsets(nums) {
    const result = [];
    const path = [];
    function visit(start) {
        result.push(path.slice());
        for (let i = start; i < nums.length; i++) {
            path.push(nums[i]);
            visit(i + 1);
            path.pop();
        }
    }
    visit(0);
    return result;
}
