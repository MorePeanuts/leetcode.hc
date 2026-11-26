function removeDuplicates(nums: number[]): number {
    let k = 0;
    for (const value of nums) {
        if (k === 0 || nums[k - 1] !== value) {
            nums[k++] = value;
        }
    }
    return k;
}
