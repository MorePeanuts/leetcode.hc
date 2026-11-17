class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int previous = 0;
        int current = 0;
        for (int i = 2; i <= cost.length; i++) {
            int oneStep = current + cost[i - 1];
            int twoSteps = previous + cost[i - 2];
            previous = current;
            current = oneStep < twoSteps ? oneStep : twoSteps;
        }
        return current;
    }
}
