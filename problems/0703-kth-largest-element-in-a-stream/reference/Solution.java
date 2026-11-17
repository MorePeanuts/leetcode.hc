import java.util.PriorityQueue;

class KthLargest {
    private final int k;
    private final PriorityQueue<Integer> heap;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        heap = new PriorityQueue<>(k);
        for (int value : nums) {
            add(value);
        }
    }

    public int add(int val) {
        if (heap.size() < k) {
            heap.add(val);
        } else if (val > heap.peek()) {
            heap.remove();
            heap.add(val);
        }
        return heap.peek();
    }
}
