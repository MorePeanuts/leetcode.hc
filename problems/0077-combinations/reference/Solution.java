import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        visit(n, 1, k, new ArrayList<>(), result);
        return result;
    }

    private void visit(int n, int start, int needed,
                       List<Integer> path, List<List<Integer>> result) {
        if (needed == 0) {
            result.add(new ArrayList<>(path));
            return;
        }
        for (int value = start; value <= n - needed + 1; value++) {
            path.add(value);
            visit(n, value + 1, needed - 1, path, result);
            path.remove(path.size() - 1);
        }
    }
}
