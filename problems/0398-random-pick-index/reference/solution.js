class Solution {
    positions = new Map();

    constructor(nums) {
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

    pick(target) {
        const indices = this.positions.get(target);
        return indices[Math.floor(Math.random() * indices.length)];
    }
}
