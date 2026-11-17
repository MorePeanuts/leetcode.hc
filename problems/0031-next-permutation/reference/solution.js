function nextPermutation(nums) {
    const n = nums.length;
    let pivot = n - 2;
    while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
        pivot--;
    }
    if (pivot >= 0) {
        let successor = n - 1;
        while (nums[successor] <= nums[pivot]) {
            successor--;
        }
        let value = nums[pivot];
        nums[pivot] = nums[successor];
        nums[successor] = value;
    }
    let left = pivot + 1;
    let right = n - 1;
    while (left < right) {
        let value = nums[left];
        nums[left++] = nums[right];
        nums[right--] = value;
    }
}
