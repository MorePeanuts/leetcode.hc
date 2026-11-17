import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> rows = new ArrayList<>(numRows);
        for (int row = 0; row < numRows; ++row) {
            List<Integer> next = new ArrayList<>(row + 1);
            next.add(1);
            for (int col = 1; col < row; ++col) {
                next.add(rows.get(row - 1).get(col - 1) + rows.get(row - 1).get(col));
            }
            if (row > 0) {
                next.add(1);
            }
            rows.add(next);
        }
        return rows;
    }
}
