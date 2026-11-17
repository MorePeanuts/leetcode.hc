function findSubsequences(nums: number[]): number[][] {
    const result: number[][] = [];
    const path: number[] = [];
    function visit(start: number): void {
        if (path.length >= 2) {
            result.push(path.slice());
        }
        const seen = new Uint8Array(201);
        for (let i = start; i < nums.length; i++) {
            const value = nums[i];
            if ((path.length > 0 && value < path[path.length - 1]) || seen[value + 100]) {
                continue;
            }
            seen[value + 100] = 1;
            path.push(value);
            visit(i + 1);
            path.pop();
        }
    }
    visit(0);
    return result;
}
