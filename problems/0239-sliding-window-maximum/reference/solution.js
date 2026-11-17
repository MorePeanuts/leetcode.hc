function maxSlidingWindow(nums, k) {
    const n = nums.length;
    const result = Array(n - k + 1);
    const queue = new Int32Array(n);
    let head = 0;
    let tail = 0;
    for (let i = 0; i < n; i++) {
        while (tail > head && nums[queue[tail - 1]] <= nums[i]) {
            tail--;
        }
        queue[tail++] = i;
        if (queue[head] <= i - k) {
            head++;
        }
        if (i >= k - 1) {
            result[i - k + 1] = nums[queue[head]];
        }
    }
    return result;
}
