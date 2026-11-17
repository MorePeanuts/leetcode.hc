int rob(int* nums, int numsSize) {
    int previous = 0;
    int current = 0;
    for (int i = 0; i < numsSize; i++) {
        int take = previous + nums[i];
        previous = current;
        if (take > current) current = take;
    }
    return current;
}
