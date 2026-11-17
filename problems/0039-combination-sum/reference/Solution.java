import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private void visit(int[] nums, List<Integer> path, int start, int remaining, List<List<Integer>> result) {
        if (remaining == 0) {
            result.add(new ArrayList<>(path));
            return;
        }
        for (int i = start; i < nums.length; i++) {
            int value = nums[i];
            if (value > remaining) {
                break;
            }
            path.add(value);
            visit(nums, path, i, remaining - value, result);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        Arrays.sort(nums);
        visit(nums, path, 0, target, result);
        return result;
    }
}
