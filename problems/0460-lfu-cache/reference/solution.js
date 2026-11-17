class Entry {
    previous = this;
    next = this;
    count = 1;

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

    empty() {
        return this.end.next === this.end;
    }
}

class LFUCache {
    entries = new Map();
    groups = new Map();
    minimum = 0;

    constructor(capacity) {
        this.capacity = capacity;
    }

    append(entry) {
        let group = this.groups.get(entry.count);
        if (group === undefined) {
            group = new Recency();
            this.groups.set(entry.count, group);
        }
        group.append(entry);
    }

    touch(entry) {
        const group = this.groups.get(entry.count);
        group.detach(entry);
        if (group.empty()) {
            this.groups.delete(entry.count);
            if (this.minimum === entry.count) this.minimum++;
        }
        entry.count++;
        this.append(entry);
    }

    get(key) {
        const entry = this.entries.get(key);
        if (entry === undefined) return -1;
        this.touch(entry);
        return entry.value;
    }

    put(key, value) {
        let entry = this.entries.get(key);
        if (entry !== undefined) {
            entry.value = value;
            this.touch(entry);
            return;
        }
        if (this.entries.size === this.capacity) {
            const group = this.groups.get(this.minimum);
            const oldest = group.oldest();
            group.detach(oldest);
            this.entries.delete(oldest.key);
            if (group.empty()) this.groups.delete(this.minimum);
        }
        entry = new Entry(key, value);
        this.entries.set(key, entry);
        this.append(entry);
        this.minimum = 1;
    }
}
