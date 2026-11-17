function sortedSquares(nums: number[]): number[] {
    const n = nums.length;
    const result: number[] = Array(n);
    let left = 0;
    let right = n - 1;
    for (let i = right; i >= 0; i--) {
        let a = nums[left] * nums[left];
        let b = nums[right] * nums[right];
        if (a > b) {
            result[i] = a;
            left++;
        } else {
            result[i] = b;
            right--;
        }
    }
    return result;
}
