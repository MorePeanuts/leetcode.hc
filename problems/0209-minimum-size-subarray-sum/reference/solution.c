int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int sum = 0;
    int best = numsSize + 1;
    for (int right = 0; right < numsSize; ++right) {
        sum += nums[right];
        while (sum >= target) {
            int size = right - left + 1;
            if (size < best) {
                best = size;
            }
            sum -= nums[left++];
        }
    }
    return best > numsSize ? 0 : best;
}
