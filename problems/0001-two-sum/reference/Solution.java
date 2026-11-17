import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            Integer match = seen.get(target - nums[i]);
            if (match != null) {
                return new int[] {match, i};
            }
            seen.put(nums[i], i);
        }
        return new int[0];
    }
}
