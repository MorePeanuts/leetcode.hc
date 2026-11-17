function findErrorNums(nums) {
    const n = nums.length;
    const seen = new Uint8Array(n + 1);
    let total = 0;
    let duplicate = 0;
    for (let i = 0; i < n; i++) {
        let value = nums[i];
        total += value;
        if (seen[value]) {
            duplicate = value;
        }
        seen[value] = 1;
    }
    let missing = n * (n + 1) / 2 - total + duplicate;
    return [duplicate, missing];
}
