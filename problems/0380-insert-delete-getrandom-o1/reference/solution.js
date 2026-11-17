class RandomizedSet {
    values = [];
    positions = new Map();

    insert(val) {
        if (this.positions.has(val)) {
            return false;
        }
        this.positions.set(val, this.values.length);
        this.values.push(val);
        return true;
    }

    remove(val) {
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

    getRandom() {
        return this.values[Math.floor(Math.random() * this.values.length)];
    }
}
