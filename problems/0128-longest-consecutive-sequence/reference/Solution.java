import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> values = new HashSet<>();
        for (int value : nums) {
            values.add(value);
        }
        int best = 0;
        for (int value : values) {
            if (value != Integer.MIN_VALUE && values.contains(value - 1)) {
                continue;
            }
            int length = 1;
            while (value != Integer.MAX_VALUE && values.contains(value + 1)) {
                value++;
                length++;
            }
            best = Math.max(best, length);
        }
        return best;
    }
}
