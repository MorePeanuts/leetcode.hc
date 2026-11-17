function containsNearbyDuplicate(nums: number[], k: number): boolean {
    const last = new Map<number, number>();
    for (let i = 0; i < nums.length; i++) {
        const previous = last.get(nums[i]);
        if (previous !== undefined && i - previous <= k) return true;
        last.set(nums[i], i);
    }
    return false;
}
