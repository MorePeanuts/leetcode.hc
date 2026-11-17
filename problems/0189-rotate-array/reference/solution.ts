function rotate(nums: number[], k: number): void {
    function reverseRange(left: number, right: number) {
        while (left < right) {
            let value = nums[left];
            nums[left++] = nums[right];
            nums[right--] = value;
        }
    }

    let n = nums.length;
    k %= n;
    reverseRange(0, n - 1);
    reverseRange(0, k - 1);
    reverseRange(k, n - 1);
}
