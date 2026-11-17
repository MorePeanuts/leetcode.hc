class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int previous = 0;
        int current = 0;
        for (int i = 2; i <= static_cast<int>(cost.size()); i++) {
            int oneStep = current + cost[i - 1];
            int twoSteps = previous + cost[i - 2];
            previous = current;
            current = oneStep < twoSteps ? oneStep : twoSteps;
        }
        return current;
    }
};
