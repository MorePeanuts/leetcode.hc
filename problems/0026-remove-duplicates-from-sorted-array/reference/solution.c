int removeDuplicates(int* nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        int value = nums[i];
        if (k == 0 || nums[k - 1] != value) {
            nums[k++] = value;
        }
    }
    return k;
}
