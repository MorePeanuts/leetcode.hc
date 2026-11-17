import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(int[] nums, List<Integer> path, int start, List<List<Integer>> result) {
        result.add(new ArrayList<>(path));
        for (int i = start; i < nums.length; i++) {
            path.add(nums[i]);
            visit(nums, path, i + 1, result);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        visit(nums, path, 0, result);
        return result;
    }
}
