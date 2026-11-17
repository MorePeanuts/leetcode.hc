function findCheapestPrice(n: number, flights: number[][], src: number, dst: number, k: number): number {
    const edges = flights.length;
    let distance = new Int32Array(n);
    for (let i = 0; i < n; i++) {
        distance[i] = 1000000000;
    }
    distance[src] = 0;
    for (let round = 0; round <= k; round++) {
        const following = distance.slice();
        for (let i = 0; i < edges; i++) {
            let from = flights[i][0];
            let to = flights[i][1];
            let candidate = distance[from] + flights[i][2];
            if (candidate < following[to]) {
                following[to] = candidate;
            }
        }
        distance = following;
    }
    return distance[dst] === 1000000000 ? -1 : distance[dst];
}
