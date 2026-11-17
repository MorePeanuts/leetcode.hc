function findMedianSortedArrays(a: number[], b: number[]): number {
    const m = a.length;
    const n = b.length;
    if (m > n) {
        return findMedianSortedArrays(b, a);
    }
    let left = 0;
    let right = m;
    const half = Math.floor((m + n + 1) / 2);
    while (left <= right) {
        const i = left + Math.floor((right - left) / 2);
        const j = half - i;
        const aLeft = i == 0 ? -Infinity : a[i - 1];
        const aRight = i == m ? Infinity : a[i];
        const bLeft = j == 0 ? -Infinity : b[j - 1];
        const bRight = j == n ? Infinity : b[j];

        if (aLeft > bRight) {
            right = i - 1;
        } else if (bLeft > aRight) {
            left = i + 1;
        } else {
            const lower = Math.max(aLeft, bLeft);
            if ((m + n) % 2 != 0) {
                return lower;
            }
            const upper = Math.min(aRight, bRight);
            return (lower + upper) / 2.0;
        }
    }
    return 0;
}
