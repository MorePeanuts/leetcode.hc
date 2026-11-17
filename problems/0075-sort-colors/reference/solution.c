void sortColors(int* nums, int numsSize) {
    int low = 0;
    int scan = 0;
    int high = numsSize - 1;
    while (scan <= high) {
        if (nums[scan] == 0) {
            nums[scan++] = nums[low];
            nums[low++] = 0;
        } else if (nums[scan] == 2) {
            nums[scan] = nums[high];
            nums[high--] = 2;
        } else {
            ++scan;
        }
    }
}
