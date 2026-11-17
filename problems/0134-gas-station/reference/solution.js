function canCompleteCircuit(gas, cost) {
    let start = 0;
    let total = 0;
    let tank = 0;
    for (let i = 0; i < gas.length; i++) {
        let net = gas[i] - cost[i];
        total += net;
        tank += net;
        if (tank < 0) {
            tank = 0;
            start = i + 1;
        }
    }
    return total >= 0 ? start : -1;
}
