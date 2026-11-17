import java.util.Map;
import java.util.TreeMap;

class MyCalendar {
    private final TreeMap<Integer, Integer> events = new TreeMap<>();

    public boolean book(int startTime, int endTime) {
        Map.Entry<Integer, Integer> before = events.lowerEntry(startTime);
        Map.Entry<Integer, Integer> after = events.ceilingEntry(startTime);
        if (before != null && before.getValue() > startTime) return false;
        if (after != null && after.getKey() < endTime) return false;
        events.put(startTime, endTime);
        return true;
    }
}
