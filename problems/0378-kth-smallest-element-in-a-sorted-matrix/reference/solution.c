typedef struct {
    int value;
    int row;
    int column;
} Entry;

static void down(Entry* heap, int size, int i) {
    Entry root = heap[i];
    for (int child = 2 * i + 1; child < size; child = 2 * i + 1) {
        if (child + 1 < size && heap[child + 1].value < heap[child].value) child++;
        if (root.value <= heap[child].value) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = root;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    Entry heap[300]; // The matrix has at most 300 rows.
    int size = k < matrixSize ? k : matrixSize;
    for (int row = 0; row < size; row++) heap[row] = (Entry){matrix[row][0], row, 0};
    for (int i = size / 2 - 1; i >= 0; i--) down(heap, size, i);
    for (int i = 1; i < k; i++) {
        Entry root = heap[0];
        int next = root.column + 1;
        heap[0] = next < matrixSize ? (Entry){matrix[root.row][next], root.row, next}
                                   : heap[--size];
        down(heap, size, 0);
    }
    return heap[0].value;
}
