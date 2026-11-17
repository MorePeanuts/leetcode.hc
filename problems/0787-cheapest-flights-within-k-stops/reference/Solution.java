class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int edges = flights.length;
        int[] distance = new int[n];
        for (int i = 0; i < n; i++) {
            distance[i] = 1000000000;
        }
        distance[src] = 0;
        for (int round = 0; round <= k; round++) {
            int[] following = distance.clone();
            for (int i = 0; i < edges; i++) {
                int from = flights[i][0];
                int to = flights[i][1];
                int candidate = distance[from] + flights[i][2];
                if (candidate < following[to]) {
                    following[to] = candidate;
                }
            }
            distance = following;
        }
        return distance[dst] == 1000000000 ? -1 : distance[dst];
    }
}
