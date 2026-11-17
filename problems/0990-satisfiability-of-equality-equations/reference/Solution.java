class Solution {
    private int find(int[] parent, int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    public boolean equationsPossible(String[] equations) {
        int[] parent = new int[26];
        int[] size = new int[26];
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < equations.length; i++) {
            if (equations[i].charAt(1) == '=') {
                int a = find(parent, equations[i].charAt(0) - 'a');
                int b = find(parent, equations[i].charAt(3) - 'a');
                if (a == b) continue;
                if (size[a] < size[b]) {
                    int temporary = a;
                    a = b;
                    b = temporary;
                }
                parent[b] = a;
                size[a] += size[b];
            }
        }
        for (int i = 0; i < equations.length; i++) {
            if (equations[i].charAt(1) == '!' && find(parent, equations[i].charAt(0) - 'a') == find(parent, equations[i].charAt(3) - 'a')) return false;
        }
        return true;
    }
}
