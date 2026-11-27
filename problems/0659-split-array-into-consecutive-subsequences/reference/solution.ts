function isPossible(nums: number[]): boolean {
    let previousCount = 0, singles = 0, pairs = 0;
    for (let start = 0; start < nums.length; ) {
        if (start > 0 && nums[start] !== nums[start - 1] + 1) {
            if (singles + pairs > 0) return false;
            previousCount = 0;
        }
        let end = start + 1;
        while (end < nums.length && nums[end] === nums[start]) end++;
        const count = end - start;

        // Every short sequence must receive a copy before longer ones can extend.
        if (count < singles + pairs) return false;
        pairs = singles;
        singles = count > previousCount ? count - previousCount : 0;
        previousCount = count;
        start = end;
    }
    return singles + pairs === 0;
}
