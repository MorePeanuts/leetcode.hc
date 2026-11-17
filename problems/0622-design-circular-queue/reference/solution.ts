class MyCircularQueue {
    private head = 0;
    private size = 0;
    private readonly data: Int32Array;

    constructor(k: number) {
        this.data = new Int32Array(k);
    }

    enQueue(value: number): boolean {
        if (this.isFull()) return false;
        this.data[(this.head + this.size) % this.data.length] = value;
        this.size++;
        return true;
    }

    deQueue(): boolean {
        if (this.isEmpty()) return false;
        this.head = (this.head + 1) % this.data.length;
        this.size--;
        return true;
    }

    Front(): number { return this.isEmpty() ? -1 : this.data[this.head]; }
    Rear(): number { return this.isEmpty() ? -1 : this.data[(this.head + this.size - 1) % this.data.length]; }
    isEmpty(): boolean { return this.size === 0; }
    isFull(): boolean { return this.size === this.data.length; }
}
