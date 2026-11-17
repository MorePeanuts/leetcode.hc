import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> first = new HashMap<>();
        first.put(0, -1);
        int remainder = 0;
        for (int i = 0; i < nums.length; i++) {
            remainder = (int)(((long)remainder + nums[i]) % k);
            Integer previous = first.putIfAbsent(remainder, i);
            if (previous != null && i - previous >= 2) {
                return true;
            }
        }
        return false;
    }
}
