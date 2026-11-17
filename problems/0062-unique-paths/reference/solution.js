function uniquePaths(m, n) {
    const row = new Int32Array(n);
    for (let j = 0; j < n; j++) row[j] = 1;
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) row[j] += row[j - 1];
    }
    return row[n - 1];
}
