function sortArray(nums) {
    function siftDown(root, n) {
        let value = nums[root];
        for (let child = 2 * root + 1; child < n; child = 2 * root + 1) {
            if (child + 1 < n && nums[child] < nums[child + 1]) child++;
            if (nums[child] <= value) break;
            nums[root] = nums[child];
            root = child;
        }
        nums[root] = value;
    }

    let n = nums.length;
    for (let root = Math.floor(n / 2) - 1; root >= 0; root--) siftDown(root, n);

    for (let end = n - 1; end > 0; end--) {
        let value = nums[0];
        nums[0] = nums[end];
        nums[end] = value;
        siftDown(0, end);
    }
    return nums;
}
