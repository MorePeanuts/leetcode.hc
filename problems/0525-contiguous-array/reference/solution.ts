function findMaxLength(nums: number[]): number {
    let n = nums.length;
    const first = new Int32Array(2 * n + 1);
    // Store index plus one, reserving zero for balances not yet seen.
    let balance = n;
    first[balance] = -1;
    let answer = 0;
    for (let i = 0; i < n; ++i) {
        balance += nums[i] === 1 ? 1 : -1;
        if (first[balance] !== 0) {
            let previous = first[balance] < 0 ? -1 : first[balance] - 1;
            let size = i - previous;
            if (size > answer) {
                answer = size;
            }
        } else {
            first[balance] = i + 1;
        }
    }
    return answer;
}
