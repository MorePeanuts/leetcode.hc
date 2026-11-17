function insert(intervals: number[][], newInterval: number[]): number[][] {
    const n = intervals.length;
    const result: number[][] = [];
    let low = newInterval[0];
    let high = newInterval[1];
    let i = 0;
    while (i < n && intervals[i][1] < low) {
        result.push(intervals[i++]);
    }
    while (i < n && intervals[i][0] <= high) {
        if (intervals[i][0] < low) {
            low = intervals[i][0];
        }
        if (intervals[i][1] > high) {
            high = intervals[i][1];
        }
        i++;
    }
    result.push([low, high]);
    while (i < n) {
        result.push(intervals[i++]);
    }
    return result;
}
