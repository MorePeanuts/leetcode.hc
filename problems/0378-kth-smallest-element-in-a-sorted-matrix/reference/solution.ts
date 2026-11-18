function kthSmallest(matrix: number[][], k: number): number {
    const n = matrix.length;
    let lo = matrix[0][0];
    let hi = matrix[n - 1][n - 1];
    while (lo < hi) {
        const mid = lo + Math.floor((hi - lo) / 2);
        let count = 0;
        let row = n - 1;
        let column = 0;
        while (row >= 0 && column < n) {
            if (matrix[row][column] <= mid) {
                count += row + 1;
                column++;
            } else {
                row--;
            }
        }
        if (count < k) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
