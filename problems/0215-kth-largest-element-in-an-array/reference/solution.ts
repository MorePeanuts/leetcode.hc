function findKthLargest(nums: number[], k: number): number {
    const counts = new Int32Array(20001);
    for (const value of nums) counts[value + 10000]++;
    for (let value = 20000; value >= 0; value--) {
        k -= counts[value];
        if (k <= 0) return value - 10000;
    }
    return 0;
}
