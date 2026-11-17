class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        int[] best = new int[n];
            boolean[] used = new boolean[n];
        for (int i = 1; i < n; i++) best[i] = Integer.MAX_VALUE;
        best[0] = 0;
        int total = 0;
        for (int count = 0; count < n; count++) {
            int vertex = -1;
            for (int i = 0; i < n; i++) {
                if (!used[i] && (vertex < 0 || best[i] < best[vertex])) vertex = i;
            }
            used[vertex] = true;
            total += best[vertex];
            for (int i = 0; i < n; i++) {
                if (used[i]) continue;
                int distance = Math.abs(points[vertex][0] - points[i][0]) + Math.abs(points[vertex][1] - points[i][1]);
                if (distance < best[i]) best[i] = distance;
            }
        }
        return total;
    }
}
