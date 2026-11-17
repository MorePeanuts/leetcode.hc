import java.util.ArrayDeque;

class MinStack {
    private record Entry(int value, int minimum) {}
    private final ArrayDeque<Entry> entries = new ArrayDeque<>();

    public void push(int value) {
        int minimum = entries.isEmpty() ? value : Math.min(value, entries.peek().minimum());
        entries.push(new Entry(value, minimum));
    }

    public void pop() { entries.pop(); }
    public int top() { return entries.peek().value(); }
    public int getMin() { return entries.peek().minimum(); }
}
