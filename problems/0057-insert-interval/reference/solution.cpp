class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        vector<vector<int>> result;
        result.reserve(n + 1);
        int low = newInterval[0];
        int high = newInterval[1];
        int i = 0;
        while (i < n && intervals[i][1] < low) {
            result.push_back(intervals[i++]);
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
        result.push_back({low, high});
        while (i < n) {
            result.push_back(intervals[i++]);
        }
        return result;
    }
};
