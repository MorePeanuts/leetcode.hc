import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int slidingPuzzle(int[][] board) {
        int[][] neighbors = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        StringBuilder start = new StringBuilder();
        for (int[] row : board) {
            for (int tile : row) start.append(tile);
        }
        ArrayDeque<String> queue = new ArrayDeque<>();
        Set<String> seen = new HashSet<>();
        queue.add(start.toString());
        seen.add(start.toString());
        for (int moves = 0; !queue.isEmpty(); moves++) {
            for (int count = queue.size(); count > 0; count--) {
                String state = queue.remove();
                if (state.equals("123450")) return moves;
                int blank = state.indexOf('0');
                for (int to : neighbors[blank]) {
                    char[] tiles = state.toCharArray();
                    tiles[blank] = tiles[to];
                    tiles[to] = '0';
                    String next = new String(tiles);
                    if (seen.add(next)) queue.add(next);
                }
            }
        }
        return -1;
    }
}
