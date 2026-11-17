import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(int[][] graph, int size, List<List<Integer>> result, List<Integer> path, int node) {
        if (node == size - 1) {
            result.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < graph[node].length; ++i) {
            int value = graph[node][i];
            path.add(value);
            visit(graph, size, result, path, value);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int size = graph.length;
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        visit(graph, size, result, path, 0);
        return result;
    }
}
