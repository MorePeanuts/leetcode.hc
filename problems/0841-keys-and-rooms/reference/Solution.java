class Solution {
    public boolean canVisitAllRooms(int[][] rooms) {
        int n = rooms.length;
        int[] color = new int[n];
            int[] stack = new int[n];
        color[0] = 1;
        stack[0] = 0;
        int count = 1;
        int visited = 1;
        while (count > 0) {
            int node = stack[--count];
            for (int neighbor : rooms[node]) {
                if (color[neighbor] == 0) {
                    color[neighbor] = 1;
                    stack[count++] = neighbor;
                    visited++;
                }
            }
        }
        return visited == n;
    }
}
