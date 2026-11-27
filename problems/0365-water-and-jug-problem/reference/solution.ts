function canMeasureWater(x: number, y: number, target: number): boolean {
    if (target > x + y) {
        return false;
    }
    while (y !== 0) {
        const remainder = x % y;
        x = y;
        y = remainder;
    }
    return target % x === 0;
}
