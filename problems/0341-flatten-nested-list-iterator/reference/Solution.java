import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

class NestedIterator implements Iterator<Integer> {
    private final Deque<Iterator<NestedInteger>> frames = new ArrayDeque<>();
    private Integer pending;

    public NestedIterator(List<NestedInteger> nestedList) {
        frames.push(nestedList.iterator());
    }

    @Override
    public Integer next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        Integer value = pending;
        pending = null;
        return value;
    }

    @Override
    public boolean hasNext() {
        while (pending == null && !frames.isEmpty()) {
            Iterator<NestedInteger> frame = frames.peek();
            if (!frame.hasNext()) {
                frames.pop();
                continue;
            }
            NestedInteger value = frame.next();
            if (value.isInteger()) {
                pending = value.getInteger();
            } else {
                frames.push(value.getList().iterator());
            }
        }
        return pending != null;
    }
}
