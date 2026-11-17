function mergeTriplets(triplets: number[][], target: number[]): boolean {
    const n = triplets.length;
    const best = [0, 0, 0];
    for (let j = 0; j < n; j++) {
        if (triplets[j][0] > target[0] || triplets[j][1] > target[1] || triplets[j][2] > target[2]) {
            continue;
        }
        for (let i = 0; i < 3; i++) {
            if (triplets[j][i] > best[i]) {
                best[i] = triplets[j][i];
            }
        }
    }
    return best[0] === target[0] && best[1] === target[1] && best[2] === target[2];
}
