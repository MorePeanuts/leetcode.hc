function subsets(nums: number[]): number[][] {
    const result: number[][] = [];
    const path: number[] = [];
    function visit(start: number): void {
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
