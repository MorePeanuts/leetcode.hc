class RandomizedSet {
    private readonly values: number[] = [];
    private readonly positions = new Map<number, number>();

    insert(val: number): boolean {
        if (this.positions.has(val)) {
            return false;
        }
        this.positions.set(val, this.values.length);
        this.values.push(val);
        return true;
    }

    remove(val: number): boolean {
        const index = this.positions.get(val);
        if (index === undefined) {
            return false;
        }
        const last = this.values[this.values.length - 1];
        this.values[index] = last;
        this.positions.set(last, index);
        this.values.pop();
        this.positions.delete(val);
        return true;
    }

    getRandom(): number {
        return this.values[Math.floor(Math.random() * this.values.length)];
    }
}
