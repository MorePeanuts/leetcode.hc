import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class TimeMap {
    private record Entry(int timestamp, String value) {}
    private final Map<String, List<Entry>> histories = new HashMap<>();

    public void set(String key, String value, int timestamp) {
        histories.computeIfAbsent(key, unused -> new ArrayList<>()).add(new Entry(timestamp, value));
    }

    public String get(String key, int timestamp) {
        List<Entry> history = histories.get(key);
        if (history == null) {
            return "";
        }
        int left = 0;
        int right = history.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (history.get(mid).timestamp() <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left == 0 ? "" : history.get(left - 1).value();
    }
}
