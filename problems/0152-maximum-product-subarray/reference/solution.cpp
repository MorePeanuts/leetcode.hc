class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int smallest = nums[0];
        int largest = nums[0];
        int answer = nums[0];
        for (int i = 1; i < n; i++) {
            int value = nums[i];
            int a = smallest * value;
            int b = largest * value;
            int lower = a < b ? a : b;
            int upper = a > b ? a : b;
            smallest = value < lower ? value : lower;
            largest = value > upper ? value : upper;
            answer = answer > largest ? answer : largest;
        }
        return answer;
    }
};
