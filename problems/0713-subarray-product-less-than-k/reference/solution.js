function numSubarrayProductLessThanK(nums, k) {
    const n = nums.length;
    if (k <= 1) {
        return 0;
    }
    let product = 1;
    let left = 0;
    let answer = 0;
    for (let right = 0; right < n; right++) {
        product *= nums[right];
        while (product >= k) {
            product /= nums[left++];
        }
        answer += right - left + 1;
    }
    return answer;
}
