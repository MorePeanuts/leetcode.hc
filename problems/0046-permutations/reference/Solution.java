import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(int[] nums, int start, List<List<Integer>> result) {
        if (start == nums.length) {
            List<Integer> order = new ArrayList<>(nums.length);
            for (int v : nums) {
                order.add(v);
            }
            result.add(order);
            return;
        }
        for (int i = start; i < nums.length; i++) {
            int value = nums[start];
            nums[start] = nums[i];
            nums[i] = value;
            visit(nums, start + 1, result);
            nums[i] = nums[start];
            nums[start] = value;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        visit(nums, 0, result);
        return result;
    }
}
