class Solution {
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        int n = triplets.size();
        int best[3] = {};
        for (int j = 0; j < n; j++) {
            if (triplets[j][0] > target[0] || triplets[j][1] > target[1] || triplets[j][2] > target[2]) {
                continue;
            }
            for (int i = 0; i < 3; i++) {
                if (triplets[j][i] > best[i]) {
                    best[i] = triplets[j][i];
                }
            }
        }
        return best[0] == target[0] && best[1] == target[1] && best[2] == target[2];
    }
};
