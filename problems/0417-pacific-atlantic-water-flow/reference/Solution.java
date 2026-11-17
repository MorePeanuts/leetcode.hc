import java.util.ArrayList;
import java.util.List;

class Solution {
    private static void reach(int[][] heights, int rows, int cols, boolean far, boolean[] seen) {
        int[] queue = new int[rows * cols];
        int head = 0;
        int tail = 0;
        int side = far ? cols - 1 : 0;
        int edge = far ? rows - 1 : 0;
        for (int r = 0; r < rows; r++) {
            int index = r * cols + side;
            seen[index] = true;
            queue[tail++] = index;
        }
        for (int c = 0; c < cols; c++) {
            int index = edge * cols + c;
            if (!seen[index]) {
                seen[index] = true;
                queue[tail++] = index;
            }
        }
        int[] dy = {-1, 1, 0, 0};
        int[] dx = {0, 0, -1, 1};
        while (head < tail) {
            int index = queue[head++];
            int row = index / cols;
            int col = index % cols;
            for (int d = 0; d < 4; d++) {
                int r = row + dy[d];
                int c = col + dx[d];
                if (r < 0 || r >= rows || c < 0 || c >= cols) {
                    continue;
                }
                int next = r * cols + c;
                if (!seen[next] && heights[r][c] >= heights[row][col]) {
                    seen[next] = true;
                    queue[tail++] = next;
                }
            }
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;
        int total = rows * cols;
        boolean[] pacific = new boolean[total];
        boolean[] atlantic = new boolean[total];
        reach(heights, rows, cols, false, pacific);
        reach(heights, rows, cols, true, atlantic);
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < total; i++) {
            if (pacific[i] && atlantic[i]) {
                result.add(List.of(i / cols, i % cols));
            }
        }
        return result;
    }
}
