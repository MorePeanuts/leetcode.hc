function topKFrequent(nums, k) {
    const counts = new Map();
    for (const value of nums) {
        counts.set(value, (counts.get(value) ?? 0) + 1);
    }
    const buckets = new Array(nums.length + 1);
    for (const [value, frequency] of counts) {
        (buckets[frequency] ??= []).push(value);
    }
    const result = [];
    for (let f = nums.length; f > 0 && result.length < k; --f) {
        const bucket = buckets[f];
        if (bucket === undefined) {
            continue;
        }
        for (const value of bucket) {
            result.push(value);
            if (result.length === k) {
                break;
            }
        }
    }
    return result;
}
