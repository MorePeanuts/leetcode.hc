function lastStoneWeight(stones) {
    function siftDown(root, n) {
        let value = stones[root];
        for (let child = 2 * root + 1; child < n; child = 2 * root + 1) {
            if (child + 1 < n && stones[child] < stones[child + 1]) child++;
            if (stones[child] <= value) break;
            stones[root] = stones[child];
            root = child;
        }
        stones[root] = value;
    }

    let n = stones.length;
    for (let root = Math.floor(n / 2) - 1; root >= 0; root--) siftDown(root, n);

    while (n > 1) {
        let first = stones[0];
        stones[0] = stones[--n];
        siftDown(0, n);
        let second = stones[0];
        if (first === second) {
            stones[0] = stones[--n];
        } else {
            stones[0] = first - second;
        }
        if (n > 0) siftDown(0, n);
    }
    return n > 0 ? stones[0] : 0;
}
