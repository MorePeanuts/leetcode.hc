import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        visit(1, k, n, new ArrayList<>(), result);
        return result;
    }

    private void visit(int start, int needed, int remaining,
                       List<Integer> path, List<List<Integer>> result) {
        if (needed == 0) {
            if (remaining == 0) {
                result.add(new ArrayList<>(path));
            }
            return;
        }
        for (int value = start; value <= 9 - needed + 1 && value <= remaining; value++) {
            path.add(value);
            visit(value + 1, needed - 1, remaining - value, path, result);
            path.remove(path.size() - 1);
        }
    }
}
