import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;

class LFUCache {
    private static class Entry {
        int value;
        int count = 1;

        Entry(int value) {
            this.value = value;
        }
    }

    private final int capacity;
    private int minimum;
    private final Map<Integer, Entry> entries = new HashMap<>();
    private final Map<Integer, LinkedHashSet<Integer>> groups = new HashMap<>();

    public LFUCache(int capacity) {
        this.capacity = capacity;
    }

    private void touch(int key, Entry entry) {
        LinkedHashSet<Integer> previous = groups.get(entry.count);
        previous.remove(key);
        if (previous.isEmpty()) {
            groups.remove(entry.count);
            if (entry.count == minimum) minimum++;
        }
        groups.computeIfAbsent(++entry.count, count -> new LinkedHashSet<>()).add(key);
    }

    public int get(int key) {
        Entry entry = entries.get(key);
        if (entry == null) return -1;
        touch(key, entry);
        return entry.value;
    }

    public void put(int key, int value) {
        Entry entry = entries.get(key);
        if (entry != null) {
            entry.value = value;
            touch(key, entry);
            return;
        }
        if (entries.size() == capacity) {
            LinkedHashSet<Integer> group = groups.get(minimum);
            int oldest = group.iterator().next();
            group.remove(oldest);
            entries.remove(oldest);
            if (group.isEmpty()) groups.remove(minimum);
        }
        entries.put(key, new Entry(value));
        groups.computeIfAbsent(1, count -> new LinkedHashSet<>()).add(key);
        minimum = 1;
    }
}
