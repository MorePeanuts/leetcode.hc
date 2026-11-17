import java.util.Comparator;
import java.util.PriorityQueue;

class MedianFinder {
    private record Entry(double priority, int value) {}

    private final PriorityQueue<Entry> low = new PriorityQueue<>(Comparator.comparingDouble(Entry::priority));
    private final PriorityQueue<Entry> high = new PriorityQueue<>(Comparator.comparingDouble(Entry::priority));

    public void addNum(int num) {
        if (low.size() > 0 && num > -low.peek().priority()) {
            high.add(new Entry(num, num));
        } else {
            low.add(new Entry(-num, num));
        }
        if (low.size() > high.size() + 1) {
            Entry entry = low.remove();
            high.add(new Entry(entry.value(), entry.value()));
        } else if (high.size() > low.size()) {
            Entry entry = high.remove();
            low.add(new Entry(-entry.value(), entry.value()));
        }
    }

    public double findMedian() {
        if (low.size() > high.size()) {
            return -low.peek().priority();
        }
        return (high.peek().priority() - low.peek().priority()) / 2;
    }
}
