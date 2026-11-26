int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        int value = nums[i];
        if (value != val) {
            nums[k++] = value;
        }
    }
    return k;
}
