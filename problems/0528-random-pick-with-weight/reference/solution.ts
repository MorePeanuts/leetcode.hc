class Solution {
    private readonly prefix: number[];
    constructor(w: number[]) {
        let total = 0;
        this.prefix = w.map(value => total += value);
    }

    pickIndex(): number {
        const target = Math.floor(Math.random() * this.prefix[this.prefix.length - 1]);
        let lo = 0;
        let hi = this.prefix.length - 1;
        while (lo < hi) {
            const mid = lo + Math.floor((hi - lo) / 2);
            if (this.prefix[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
