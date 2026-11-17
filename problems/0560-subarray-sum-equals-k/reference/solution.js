function subarraySum(nums, k) {
    const seen = new Map([[0, 1]]);
    let prefix = 0;
    let answer = 0;
    for (const value of nums) {
        prefix += value;
        answer += seen.get(prefix - k) ?? 0;
        seen.set(prefix, 1 + (seen.get(prefix) ?? 0));
    }
    return answer;
}
