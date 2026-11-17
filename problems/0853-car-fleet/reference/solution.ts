

function carFleet(target: number, position: number[], speed: number[]): number {
    const cars = position.map((p, i) => [p, speed[i]]);
    cars.sort((a, b) => b[0] - a[0]);
    let fleets = 0;
    let slowest = 0;
    for (let i = 0; i < position.length; ++i) {
        let time = (target - cars[i][0]) / cars[i][1];
        if (time > slowest) {
            ++fleets;
            slowest = time;
        }
    }

    return fleets;
}
