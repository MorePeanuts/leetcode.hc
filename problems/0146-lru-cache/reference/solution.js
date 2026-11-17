class Entry {
    previous = this;
    next = this;

    constructor(key, value) {
        this.key = key;
        this.value = value;
    }
}

class Recency {
    end = new Entry(0, 0);

    append(entry) {
        entry.previous = this.end.previous;
        entry.next = this.end;
        entry.previous.next = entry;
        this.end.previous = entry;
    }

    detach(entry) {
        entry.previous.next = entry.next;
        entry.next.previous = entry.previous;
    }

    oldest() {
        return this.end.next;
    }
}

class LRUCache {
    entries = new Map();
    order = new Recency();

    constructor(capacity) {
        this.capacity = capacity;
    }

    get(key) {
        const entry = this.entries.get(key);
        if (entry === undefined) return -1;
        this.order.detach(entry);
        this.order.append(entry);
        return entry.value;
    }

    put(key, value) {
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
