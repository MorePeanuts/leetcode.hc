function searchRange(nums: number[], target: number): number[] {
    const n = nums.length;
    let low = 0;
    let high = n;
    while (low < high) {
        let mid = low + Math.floor((high - low) / 2);
        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    let first = -1;
    let last = -1;
    if (low < n && nums[low] === target) {
        first = low;
        high = n;
        while (low < high) {
            let mid = low + Math.floor((high - low) / 2);
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        last = low - 1;
    }
    return [first, last];
}
