import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private void visit(int[] values, int size, List<List<Integer>> result, List<Integer> path, int start) {
        result.add(new ArrayList<>(path));
        for (int i = start; i < size; ++i) {
            int value = values[i];

            if (i > start && value == values[i - 1]) {
                continue;
            }
            path.add(value);
            visit(values, size, result, path, i + 1);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] values) {
        Arrays.sort(values);
        int size = values.length;
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        visit(values, size, result, path, 0);
        return result;
    }
}
