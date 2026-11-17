import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(int[] nums, List<Integer> path, int start, List<List<Integer>> result) {
        if (path.size() >= 2) {
            result.add(new ArrayList<>(path));
        }
        boolean[] seen = new boolean[201];
        for (int i = start; i < nums.length; i++) {
            int value = nums[i];
            if ((!path.isEmpty() && value < path.get(path.size() - 1)) || seen[value + 100]) {
                continue;
            }
            seen[value + 100] = true;
            path.add(value);
            visit(nums, path, i + 1, result);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        visit(nums, path, 0, result);
        return result;
    }
}
