void moveZeroes(int* nums, int numsSize) {
    int write = 0;
    for (int read = 0; read < numsSize; ++read) {
        if (nums[read] != 0) {
            int temp = nums[write];
            nums[write] = nums[read];
            nums[read] = temp;
            ++write;
        }
    }
}
