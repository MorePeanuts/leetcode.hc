function removeDuplicates(nums) {
    let length = 0;
    for (let i = 0; i < nums.length; i++) {
        let value = nums[i];
        if (length < 2 || value !== nums[length - 2]) {
            nums[length] = value;
            length++;
        }
    }
    return length;
}
