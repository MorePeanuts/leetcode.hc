static int robRange(int* nums, int left, int right) {
    int previous = 0;
    int current = 0;
    for (int i = left; i < right; i++) {
        int take = previous + nums[i];
        previous = current;
        if (take > current) current = take;
    }
    return current;
}

int rob(int* nums, int numsSize) {
    int n = numsSize;
    if (n == 1) return nums[0];
    int left = robRange(nums, 0, n - 1);
    int right = robRange(nums, 1, n);
    return left > right ? left : right;
}
