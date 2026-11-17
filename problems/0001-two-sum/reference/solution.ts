function twoSum(nums: number[], target: number): number[] {
    const seen = new Map<number, number>();
    for (let i = 0; i < nums.length; ++i) {
        const match = seen.get(target - nums[i]);
        if (match !== undefined) {
            return [match, i];
        }
        seen.set(nums[i], i);
    }
    return [];
}
