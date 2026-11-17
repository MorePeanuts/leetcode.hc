class Entry {
    previous: Entry = this;
    next: Entry = this;

    constructor(readonly key: number, public value: number) {}
}

class Recency {
    end = new Entry(0, 0);

    append(entry: Entry): void {
        entry.previous = this.end.previous;
        entry.next = this.end;
        entry.previous.next = entry;
        this.end.previous = entry;
    }

    detach(entry: Entry): void {
        entry.previous.next = entry.next;
        entry.next.previous = entry.previous;
    }

    oldest(): Entry {
        return this.end.next;
    }
}

class LRUCache {
    private readonly entries = new Map<number, Entry>();
    private readonly order = new Recency();

    constructor(private readonly capacity: number) {}

    get(key: number): number {
        const entry = this.entries.get(key);
        if (entry === undefined) return -1;
        this.order.detach(entry);
        this.order.append(entry);
        return entry.value;
    }

    put(key: number, value: number): void {
        let entry = this.entries.get(key);
        if (entry !== undefined) {
            this.order.detach(entry);
            entry.value = value;
        } else {
            if (this.entries.size === this.capacity) {
                const old = this.order.oldest();
                this.order.detach(old);
                this.entries.delete(old.key);
            }
            entry = new Entry(key, value);
            this.entries.set(key, entry);
        }
        this.order.append(entry);
    }
}
