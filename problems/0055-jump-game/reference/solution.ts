function canJump(nums: number[]): boolean {
    let farthest = 0;
    for (let i = 0; i <= farthest; ++i) {
        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
        }
        if (farthest >= nums.length - 1) {
            return true;
        }
    }
    return false;
}
