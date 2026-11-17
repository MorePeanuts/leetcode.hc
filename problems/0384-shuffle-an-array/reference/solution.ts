class Solution {
    private readonly original: number[];

    constructor(nums: number[]) {
        this.original = nums.slice();
    }

    reset(): number[] {
        return this.original.slice();
    }

    shuffle(): number[] {
        const result = this.reset();
        for (let i = result.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [result[i], result[j]] = [result[j], result[i]];
        }
        return result;
    }
}
