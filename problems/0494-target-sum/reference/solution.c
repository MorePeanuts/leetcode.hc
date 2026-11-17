int findTargetSumWays(int* nums, int numsSize, int target) {
    int total = 0;
    for (int i = 0; i < numsSize; ++i) {
        total += nums[i];
    }
    if (target > total || target < -total || ((total + target) & 1) != 0) {
        return 0;
    }
    int goal = (total + target) >> 1;
    int* ways = calloc((size_t)(goal + 1), sizeof(*ways));
    ways[0] = 1;
    for (int i = 0; i < numsSize; ++i) {
        int value = nums[i];
        for (int subtotal = goal; subtotal >= value; --subtotal) {
            ways[subtotal] += ways[subtotal - value];
        }
    }
    int answer = ways[goal];
    free(ways);
    return answer;
}
