function eraseOverlapIntervals(intervals) {
    intervals.sort((a, b) => a[1] - b[1]);
    let end = -Infinity;
    let removed = 0;
    for (const interval of intervals) {
        if (interval[0] >= end) {
            end = interval[1];
        } else {
            removed++;
        }
    }
    return removed;
}
