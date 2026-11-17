function minEatingSpeed(piles, h) {
    const n = piles.length;
    let total = 0;
    let high = 0;
    for (let i = 0; i < n; i++) {
        total += piles[i];
        if (piles[i] > high) {
            high = piles[i];
        }
    }
    let low = Math.ceil(total / h);
    while (low < high) {
        let speed = low + Math.floor((high - low) / 2);
        let hours = 0;
        for (let i = 0; i < n; i++) {
            hours += Math.ceil(piles[i] / speed);
        }
        if (hours <= h) {
            high = speed;
        } else {
            low = speed + 1;
        }
    }
    return low;
}
