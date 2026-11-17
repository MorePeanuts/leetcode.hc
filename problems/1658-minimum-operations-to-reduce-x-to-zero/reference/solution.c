int minOperations(int* nums, int numsSize, int x) {
    int keep = -x;
    for (int i = 0; i < numsSize; ++i) {
        keep += nums[i];
    }
    if (keep < 0) {
        return -1;
    }
    int left = 0;
    int sum = 0;
    int best = keep == 0 ? 0 : -1;
    for (int right = 0; right < numsSize; ++right) {
        sum += nums[right];
        while (sum > keep) {
            sum -= nums[left++];
        }
        if (sum == keep && right - left + 1 > best) {
            best = right - left + 1;
        }
    }
    return best < 0 ? -1 : numsSize - best;
}
