function longestConsecutive(nums) {
    const values = new Set(nums);
    let best = 0;
    for (let value of values) {
        if (values.has(value - 1)) {
            continue;
        }
        let length = 1;
        while (values.has(value + 1)) {
            value++;
            length++;
        }
        best = Math.max(best, length);
    }
    return best;
}
