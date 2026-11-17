int maxSubArray(int* nums, int numsSize) {
    int current = nums[0];
    int best = current;
    for (int i = 1; i < numsSize; i++) {
        current = current > 0 ? current + nums[i] : nums[i];
        if (current > best) best = current;
    }
    return best;
}
