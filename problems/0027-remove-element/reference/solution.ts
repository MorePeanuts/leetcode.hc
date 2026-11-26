function removeElement(nums: number[], val: number): number {
    let k = 0;
    for (const value of nums) {
        if (value !== val) {
            nums[k++] = value;
        }
    }
    return k;
}
