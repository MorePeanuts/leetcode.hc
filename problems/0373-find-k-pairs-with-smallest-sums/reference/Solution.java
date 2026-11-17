import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.ArrayList;
import java.util.List;

class Solution {
    private record Entry(double priority, int value) {}

    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        int rows = nums1.length;
        int cols = nums2.length;
        int seeds = rows < k ? rows : k;
        PriorityQueue<Entry> queue = new PriorityQueue<>(Comparator.comparingDouble(Entry::priority));
        for (int i = 0; i < seeds; ++i) {
            queue.add(new Entry(nums1[i] + nums2[0], i * cols));
        }
        List<List<Integer>> result = new ArrayList<>(k);
        for (int count = 0; count < k; ++count) {
            Entry entry = queue.remove();
            int id = entry.value();
            int i = id / cols;
            int j = id % cols;
            result.add(List.of(nums1[i], nums2[j]));
            if (j + 1 < cols) {
                queue.add(new Entry(nums1[i] + nums2[j + 1], id + 1));
            }
        }

        return result;
    }
}
