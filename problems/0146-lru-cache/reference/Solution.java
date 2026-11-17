import java.util.LinkedHashMap;
import java.util.Map;

class LRUCache {
    private final int capacity;
    private final LinkedHashMap<Integer, Integer> entries = new LinkedHashMap<>(16, 0.75f, true);

    public LRUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        return entries.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        entries.put(key, value);
        if (entries.size() > capacity) {
            entries.remove(entries.keySet().iterator().next());
        }
    }
}
