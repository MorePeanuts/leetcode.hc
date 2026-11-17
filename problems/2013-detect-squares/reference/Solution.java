import java.util.HashMap;
import java.util.Map;

class DetectSquares {
    private final Map<Integer, Map<Integer, Integer>> columns = new HashMap<>();

    public void add(int[] point) {
        columns.computeIfAbsent(point[0], key -> new HashMap<>())
               .merge(point[1], 1, Integer::sum);
    }

    private int frequency(int x, int y) {
        Map<Integer, Integer> column = columns.get(x);
        return column == null ? 0 : column.getOrDefault(y, 0);
    }

    public int count(int[] point) {
        int x = point[0], y = point[1];
        int result = 0;
        Map<Integer, Integer> column = columns.get(x);
        if (column == null) return 0;
        for (var entry : column.entrySet()) {
            int otherY = entry.getKey();
            int side = otherY - y;
            if (side == 0) continue;
            result += entry.getValue() * (
                frequency(x - side, y) * frequency(x - side, otherY) +
                frequency(x + side, y) * frequency(x + side, otherY));
        }
        return result;
    }
}
