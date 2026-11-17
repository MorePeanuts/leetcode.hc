function maxProduct(nums) {
    const n = nums.length;
    let smallest = nums[0];
    let largest = nums[0];
    let answer = nums[0];
    for (let i = 1; i < n; i++) {
        let value = nums[i];
        let a = smallest * value;
        let b = largest * value;
        let lower = a < b ? a : b;
        let upper = a > b ? a : b;
        smallest = value < lower ? value : lower;
        largest = value > upper ? value : upper;
        answer = answer > largest ? answer : largest;
    }
    return answer;
}
