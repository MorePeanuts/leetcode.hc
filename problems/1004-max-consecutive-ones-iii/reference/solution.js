function longestOnes(nums, k) {
    let left = 0;
    let best = 0;
    for (let right = 0; right < nums.length; ++right) {
        k -= 1 - nums[right];
        while (k < 0) {
            k += 1 - nums[left++];
        }
        let size = right - left + 1;
        if (size > best) {
            best = size;
        }
    }
    return best;
}
