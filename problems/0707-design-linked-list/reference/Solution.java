class MyLinkedList {
    private static class Item {
        final int value;
        Item next;

        Item(int value, Item next) {
            this.value = value;
            this.next = next;
        }
    }

    private final Item head = new Item(0, null);
    private Item tail = head;
    private int size;

    private Item before(int index) {
        Item node = head;
        while (index-- > 0) node = node.next;
        return node;
    }

    public int get(int index) {
        return index >= 0 && index < size ? before(index).next.value : -1;
    }

    public void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Item previous = index == size ? tail : before(index);
        Item node = new Item(val, previous.next);
        previous.next = node;
        if (index == size) tail = node;
        size++;
    }

    public void addAtHead(int val) { addAtIndex(0, val); }
    public void addAtTail(int val) { addAtIndex(size, val); }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Item previous = before(index);
        Item removed = previous.next;
        previous.next = removed.next;
        if (removed == tail) tail = previous;
        size--;
    }
}
