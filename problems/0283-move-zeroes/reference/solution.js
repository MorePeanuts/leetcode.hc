function moveZeroes(nums) {
    let write = 0;
    for (let read = 0; read < nums.length; ++read) {
        if (nums[read] !== 0) {
            let temp = nums[write];
            nums[write] = nums[read];
            nums[read] = temp;
            ++write;
        }
    }
}
