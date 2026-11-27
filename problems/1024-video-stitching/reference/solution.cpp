class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> ends(time);
        for (const auto& clip : clips) {
            if (clip[0] < time) ends[clip[0]] = max(ends[clip[0]], clip[1]);
        }

        int used = 0, covered = 0, farthest = 0;
        for (int start = 0; start < time; start++) {
            if (ends[start] > farthest) farthest = ends[start];
            if (start == covered) {
                if (farthest == covered) return -1;
                covered = farthest;
                used++;
            }
        }
        return used;
    }
};
