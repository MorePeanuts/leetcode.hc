int jump(int* nums, int numsSize) {
    int jumps = 0;
    int end = 0;
    int farthest = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        int reach = i + nums[i];
        if (reach > farthest) farthest = reach;
        if (i == end) {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}
