function rob(nums: number[]): number {
    let previous = 0;
    let current = 0;
    for (let i = 0; i < nums.length; i++) {
        let take = previous + nums[i];
        previous = current;
        if (take > current) current = take;
    }
    return current;
}
