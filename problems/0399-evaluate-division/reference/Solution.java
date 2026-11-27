import java.util.*;

class Solution {
    private record Edge(String node, double ratio) {}

    private double quotient(Map<String, List<Edge>> graph, String start, String target) {
        if (!graph.containsKey(start) || !graph.containsKey(target)) {
            return -1.0;
        }
        Set<String> seen = new HashSet<>();
        ArrayDeque<Edge> queue = new ArrayDeque<>();
        seen.add(start);
        queue.add(new Edge(start, 1.0));
        while (!queue.isEmpty()) {
            Edge current = queue.remove();
            if (current.node().equals(target)) {
                return current.ratio();
            }
            for (Edge next : graph.get(current.node())) {
                if (seen.add(next.node())) {
                    queue.add(new Edge(next.node(), current.ratio() * next.ratio()));
                }
            }
        }
        return -1.0;
    }

    public double[] calcEquation(List<List<String>> equations, double[] values,
                                 List<List<String>> queries) {
        Map<String, List<Edge>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0), b = equations.get(i).get(1);
            graph.computeIfAbsent(a, key -> new ArrayList<>()).add(new Edge(b, values[i]));
            graph.computeIfAbsent(b, key -> new ArrayList<>()).add(new Edge(a, 1.0 / values[i]));
        }
        double[] result = new double[queries.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = quotient(graph, queries.get(i).get(0), queries.get(i).get(1));
        }
        return result;
    }
}
