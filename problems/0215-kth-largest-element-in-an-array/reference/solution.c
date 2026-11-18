int findKthLargest(int* nums, int numsSize, int k) {
    int counts[20001] = {0};
    for (int j = 0; j < numsSize; j++) counts[nums[j] + 10000]++;
    for (int value = 20000; value >= 0; value--) {
        k -= counts[value];
        if (k <= 0) return value - 10000;
    }
    return 0;
}
