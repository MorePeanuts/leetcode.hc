class Entry {
    previous: Entry = this;
    next: Entry = this;
    count = 1;

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

    empty(): boolean {
        return this.end.next === this.end;
    }
}

class LFUCache {
    private readonly entries = new Map<number, Entry>();
    private readonly groups = new Map<number, Recency>();
    private minimum = 0;

    constructor(private readonly capacity: number) {}

    private append(entry: Entry): void {
        let group = this.groups.get(entry.count);
        if (group === undefined) {
            group = new Recency();
            this.groups.set(entry.count, group);
        }
        group.append(entry);
    }

    private touch(entry: Entry): void {
        const group = this.groups.get(entry.count)!;
        group.detach(entry);
        if (group.empty()) {
            this.groups.delete(entry.count);
            if (this.minimum === entry.count) this.minimum++;
        }
        entry.count++;
        this.append(entry);
    }

    get(key: number): number {
        const entry = this.entries.get(key);
        if (entry === undefined) return -1;
        this.touch(entry);
        return entry.value;
    }

    put(key: number, value: number): void {
        let entry = this.entries.get(key);
        if (entry !== undefined) {
            entry.value = value;
            this.touch(entry);
            return;
        }
        if (this.entries.size === this.capacity) {
            const group = this.groups.get(this.minimum)!;
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
