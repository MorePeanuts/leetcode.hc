class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
            int[] stack = new int[n];
        for (int start = 0; start < n; start++) {
            if (color[start] != 0) continue;
            color[start] = 1;
            int count = 1;
            stack[0] = start;
            while (count > 0) {
                int node = stack[--count];
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == color[node]) return false;
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        stack[count++] = neighbor;
                    }
                }
            }
        }
        return true;
    }
}
