int uniquePaths(int m, int n) {
    int row[100]; // n <= 100
    for (int j = 0; j < n; j++) row[j] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) row[j] += row[j - 1];
    }
    return row[n - 1];
}
