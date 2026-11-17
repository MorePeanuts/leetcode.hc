function countPrimes(n: number): number {
    if (n < 3) {
        return 0;
    }
    const composite = new Uint8Array(n);
    for (let p = 2; p * p < n; p++) {
        if (!composite[p]) {
            for (let q = p * p; q < n; q += p) {
                composite[q] = 1;
            }
        }
    }
    let count = 0;
    for (let p = 2; p < n; p++) {
        if (!composite[p]) {
            count++;
        }
    }
    return count;
}
