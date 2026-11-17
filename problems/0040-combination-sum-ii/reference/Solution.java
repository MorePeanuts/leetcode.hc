import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private void visit(int[] values, int size, List<List<Integer>> result, List<Integer> path, int start, int remaining) {
        if (remaining == 0) {
            result.add(new ArrayList<>(path));
            return;
        }
        for (int i = start; i < size; ++i) {
            int value = values[i];
            if (value > remaining) {
                break;
            }
            if (i > start && value == values[i - 1]) {
                continue;
            }
            path.add(value);
            visit(values, size, result, path, i + 1, remaining - value);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] values, int target) {
        Arrays.sort(values);
        int size = values.length;
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        visit(values, size, result, path, 0, target);
        return result;
    }
}
