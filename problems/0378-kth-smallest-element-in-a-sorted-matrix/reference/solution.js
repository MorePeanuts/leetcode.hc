function kthSmallest(matrix, k) {
    const heap = [];
    for (let row = 0; row < Math.min(matrix.length, k); row++) {
        heap.push({ value: matrix[row][0], row, column: 0 });
    }
    function down(i) {
        const root = heap[i];
        for (let child = 2 * i + 1; child < heap.length; child = 2 * i + 1) {
            if (child + 1 < heap.length && heap[child + 1].value < heap[child].value) child++;
            if (root.value <= heap[child].value) break;
            heap[i] = heap[child];
            i = child;
        }
        heap[i] = root;
    }
    for (let i = Math.floor(heap.length / 2) - 1; i >= 0; i--) down(i);
    for (let i = 1; i < k; i++) {
        const root = heap[0];
        const column = root.column + 1;
        if (column < matrix.length) {
            heap[0] = { value: matrix[root.row][column], row: root.row, column };
        } else {
            heap[0] = heap.pop();
        }
        down(0);
    }
    return heap[0].value;
}
