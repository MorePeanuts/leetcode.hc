import java.util.Arrays;

class Solution {
    private int find(int[] parent, int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    public int[] findRedundantConnection(int[][] edges) {
        int[] parent = new int[edges.length + 1];
        int[] size = new int[edges.length + 1];
        for (int i = 1; i < parent.length; i++) parent[i] = i;
        Arrays.fill(size, 1);
        for (int[] edge : edges) {
            int a = find(parent, edge[0]);
            int b = find(parent, edge[1]);
            if (a == b) return edge;
            if (size[a] < size[b]) {
                int old = a;
                a = b;
                b = old;
            }
            parent[b] = a;
            size[a] += size[b];
        }
        return new int[0];
    }
}
