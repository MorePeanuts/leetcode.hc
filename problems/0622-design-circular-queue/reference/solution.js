class MyCircularQueue {
    head = 0;
    size = 0;


    constructor(k) {
        this.data = new Int32Array(k);
    }

    enQueue(value) {
        if (this.isFull()) return false;
        this.data[(this.head + this.size) % this.data.length] = value;
        this.size++;
        return true;
    }

    deQueue() {
        if (this.isEmpty()) return false;
        this.head = (this.head + 1) % this.data.length;
        this.size--;
        return true;
    }

    Front() { return this.isEmpty() ? -1 : this.data[this.head]; }
    Rear() { return this.isEmpty() ? -1 : this.data[(this.head + this.size - 1) % this.data.length]; }
    isEmpty() { return this.size === 0; }
    isFull() { return this.size === this.data.length; }
}
