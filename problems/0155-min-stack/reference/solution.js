class MinStack {
    entries = [];

    push(value) {
        const last = this.entries[this.entries.length - 1];
        this.entries.push([value, last === undefined ? value : Math.min(value, last[1])]);
    }

    pop() {
        this.entries.pop();
    }

    top() {
        return this.entries[this.entries.length - 1][0];
    }

    getMin() {
        return this.entries[this.entries.length - 1][1];
    }
}
