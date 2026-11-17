function matrixBlockSum(mat, k) {
    let m = mat.length;
    let n = mat[0].length;
    const prefix = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    const result = Array.from({ length: m }, () => new Array(n));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        }
    }
    for (let i = 0; i < m; i++) {
        let top = i > k ? i - k : 0;
        let bottom = i + k + 1 < m ? i + k + 1 : m;
        for (let j = 0; j < n; j++) {
            let left = j > k ? j - k : 0;
            let right = j + k + 1 < n ? j + k + 1 : n;
            result[i][j] = prefix[bottom][right] - prefix[top][right] - prefix[bottom][left] + prefix[top][left];
        }
    }
    return result;
}
