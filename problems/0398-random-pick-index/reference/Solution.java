import java.util.ArrayList;
import java.util.HashMap;
import java.util.concurrent.ThreadLocalRandom;

class Solution {
    private final HashMap<Integer, ArrayList<Integer>> positions = new HashMap<>();

    public Solution(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            positions.computeIfAbsent(nums[i], key -> new ArrayList<>()).add(i);
        }
    }

    public int pick(int target) {
        ArrayList<Integer> indices = positions.get(target);
        return indices.get(ThreadLocalRandom.current().nextInt(indices.size()));
    }
}
