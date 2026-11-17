class DetectSquares {
    columns = new Map();

    add(point) {
        const [x, y] = point;
        let column = this.columns.get(x);
        if (column === undefined) {
            column = new Map();
            this.columns.set(x, column);
        }
        column.set(y, 1 + (column.get(y) ?? 0));
    }

    frequency(x, y) {
        return this.columns.get(x)?.get(y) ?? 0;
    }

    count(point) {
        const [x, y] = point;
        const column = this.columns.get(x);
        if (column === undefined) return 0;
        let result = 0;
        for (const [otherY, multiplicity] of column) {
            const side = otherY - y;
            if (side === 0) continue;
            result += multiplicity * (
                this.frequency(x - side, y) * this.frequency(x - side, otherY) +
                this.frequency(x + side, y) * this.frequency(x + side, otherY));
        }
        return result;
    }
}
