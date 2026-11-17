function minCostClimbingStairs(cost) {
    let previous = 0;
    let current = 0;
    for (let i = 2; i <= cost.length; i++) {
        let oneStep = current + cost[i - 1];
        let twoSteps = previous + cost[i - 2];
        previous = current;
        current = oneStep < twoSteps ? oneStep : twoSteps;
    }
    return current;
}
