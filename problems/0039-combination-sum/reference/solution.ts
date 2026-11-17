function combinationSum(nums: number[], target: number): number[][] {
    const result: number[][] = [];
    const path: number[] = [];
    nums.sort((a, b) => a - b);
    function visit(start: number, remaining: number): void {
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
