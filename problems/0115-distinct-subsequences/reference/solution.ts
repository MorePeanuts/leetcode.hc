function numDistinct(s: string, t: string): number {
    let m = s.length;
    let n = t.length;
    const ways = new Int32Array(n + 1);
    ways[0] = 1;
    for (let i = 0; i < m; i++) {
        for (let j = n; j > 0; j--) {
            if (s[i] === t[j - 1]) {
                ways[j] = Math.min(2147483647, ways[j] + ways[j - 1]);
            }
        }
    }
    return ways[n];
}
