import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int value : nums) {
            counts.merge(value, 1, Integer::sum);
        }
        List<List<Integer>> buckets = new ArrayList<>(nums.length + 1);
        for (int i = 0; i <= nums.length; ++i) {
            buckets.add(null);
        }
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            int frequency = entry.getValue();
            List<Integer> bucket = buckets.get(frequency);
            if (bucket == null) {
                bucket = new ArrayList<>();
                buckets.set(frequency, bucket);
            }
            bucket.add(entry.getKey());
        }
        int[] result = new int[k];
        int size = 0;
        for (int f = nums.length; f > 0 && size < k; --f) {
            List<Integer> bucket = buckets.get(f);
            if (bucket == null) {
                continue;
            }
            for (int value : bucket) {
                result[size++] = value;
                if (size == k) {
                    break;
                }
            }
        }
        return result;
    }
}
