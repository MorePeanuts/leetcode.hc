class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        int end = INT_MIN;
        int removed = 0;
        for (const auto &interval : intervals) {
            if (interval[0] >= end) {
                end = interval[1];
            } else {
                removed++;
            }
        }
        return removed;
    }
};
