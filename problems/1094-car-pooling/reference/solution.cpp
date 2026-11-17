class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        std::vector<int> difference(1001);
        for (int i = 0; i < static_cast<int>(trips.size()); ++i) {
            difference[trips[i][1]] += trips[i][0];
            difference[trips[i][2]] -= trips[i][0];
        }
        int onboard = 0;
        bool feasible = true;
        for (int i = 0; i <= 1000; ++i) {
            onboard += difference[i];
            if (onboard > capacity) {
                feasible = false;
                break;
            }
        }
        return feasible;
    }
};
