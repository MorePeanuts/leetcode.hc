function carPooling(trips: number[][], capacity: number): boolean {
    const difference = new Int32Array(1001);
    for (let i = 0; i < trips.length; ++i) {
        difference[trips[i][1]] += trips[i][0];
        difference[trips[i][2]] -= trips[i][0];
    }
    let onboard = 0;
    let feasible = true;
    for (let i = 0; i <= 1000; ++i) {
        onboard += difference[i];
        if (onboard > capacity) {
            feasible = false;
            break;
        }
    }
    return feasible;
}
