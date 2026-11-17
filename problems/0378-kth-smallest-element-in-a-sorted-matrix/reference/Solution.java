import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private record Entry(int value, int row, int column) {}

    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Entry> heap = new PriorityQueue<>(Comparator.comparingInt(Entry::value));
        for (int row = 0; row < Math.min(matrix.length, k); row++)
            heap.add(new Entry(matrix[row][0], row, 0));
        for (int i = 1; i < k; i++) {
            Entry root = heap.remove();
            int column = root.column() + 1;
            if (column < matrix.length)
                heap.add(new Entry(matrix[root.row()][column], root.row(), column));
        }
        return heap.element().value();
    }
}
