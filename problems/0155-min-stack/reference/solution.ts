class MinStack {
    private readonly entries: [number, number][] = [];

    push(value: number): void {
        const last = this.entries[this.entries.length - 1];
        this.entries.push([value, last === undefined ? value : Math.min(value, last[1])]);
    }

    pop(): void {
        this.entries.pop();
    }

    top(): number {
        return this.entries[this.entries.length - 1][0];
    }

    getMin(): number {
        return this.entries[this.entries.length - 1][1];
    }
}
