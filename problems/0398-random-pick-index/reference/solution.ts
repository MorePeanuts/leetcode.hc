class Solution {
    private readonly positions = new Map<number, number[]>();

    constructor(nums: number[]) {
        for (let i = 0; i < nums.length; i++) {
            const value = nums[i];
            let indices = this.positions.get(value);
            if (indices === undefined) {
                indices = [];
                this.positions.set(value, indices);
            }
            indices.push(i);
        }
    }

    pick(target: number): number {
        const indices = this.positions.get(target)!;
        return indices[Math.floor(Math.random() * indices.length)];
    }
}
