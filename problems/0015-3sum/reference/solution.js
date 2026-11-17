function threeSum(nums) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const result = [];

    for (let i = 0; i + 2 < n && nums[i] <= 0; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        let left = i + 1;
        let right = n - 1;
        while (left < right) {
            let sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                result.push([nums[i], nums[left], nums[right]]);
                let lower = nums[left];
                let upper = nums[right];
                while (left < right && nums[left] === lower) {
                    left++;
                }
                while (left < right && nums[right] === upper) {
                    right--;
                }
            }
        }
    }
    return result;
}
