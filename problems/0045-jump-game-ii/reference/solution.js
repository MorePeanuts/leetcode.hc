function jump(nums) {
    let jumps = 0;
    let end = 0;
    let farthest = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        let reach = i + nums[i];
        if (reach > farthest) farthest = reach;
        if (i === end) {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}
