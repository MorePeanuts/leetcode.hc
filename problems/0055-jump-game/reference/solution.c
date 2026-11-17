bool canJump(int* nums, int numsSize) {
    int farthest = 0;
    for (int i = 0; i <= farthest; ++i) {
        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
        }
        if (farthest >= numsSize - 1) {
            return true;
        }
    }
    return false;
}
