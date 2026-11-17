class MyLinkedList {
    head = { value: 0, next: null };
    tail = this.head;
    size = 0;

    before(index) {
        let node = this.head;
        while (index-- > 0) node = node.next;
        return node;
    }

    get(index) {
        return index >= 0 && index < this.size ? this.before(index).next.value : -1;
    }

    addAtIndex(index, val) {
        if (index < 0 || index > this.size) return;
        const previous = index === this.size ? this.tail : this.before(index);
        const node = { value: val, next: previous.next };
        previous.next = node;
        if (index === this.size) this.tail = node;
        this.size++;
    }

    addAtHead(val) { this.addAtIndex(0, val); }
    addAtTail(val) { this.addAtIndex(this.size, val); }

    deleteAtIndex(index) {
        if (index < 0 || index >= this.size) return;
        const previous = this.before(index);
        const removed = previous.next;
        previous.next = removed.next;
        if (removed === this.tail) this.tail = previous;
        this.size--;
    }
}
