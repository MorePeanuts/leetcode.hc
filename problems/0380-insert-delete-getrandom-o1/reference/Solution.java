import java.util.ArrayList;
import java.util.HashMap;
import java.util.concurrent.ThreadLocalRandom;

class RandomizedSet {
    private final ArrayList<Integer> values = new ArrayList<>();
    private final HashMap<Integer, Integer> positions = new HashMap<>();

    public boolean insert(int val) {
        if (positions.putIfAbsent(val, values.size()) != null) {
            return false;
        }
        values.add(val);
        return true;
    }

    public boolean remove(int val) {
        Integer index = positions.get(val);
        if (index == null) {
            return false;
        }
        int lastIndex = values.size() - 1;
        int last = values.get(lastIndex);
        values.set(index, last);
        positions.put(last, index);
        values.remove(lastIndex);
        positions.remove(val);
        return true;
    }

    public int getRandom() {
        return values.get(ThreadLocalRandom.current().nextInt(values.size()));
    }
}
