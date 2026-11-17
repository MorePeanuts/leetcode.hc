int minCostClimbingStairs(int* cost, int costSize) {
    int previous = 0;
    int current = 0;
    for (int i = 2; i <= costSize; i++) {
        int oneStep = current + cost[i - 1];
        int twoSteps = previous + cost[i - 2];
        previous = current;
        current = oneStep < twoSteps ? oneStep : twoSteps;
    }
    return current;
}
