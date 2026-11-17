class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = nums.size();
        if (k <= 1) {
            return 0;
        }
        int product = 1;
        int left = 0;
        int answer = 0;
        for (int right = 0; right < n; right++) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left++];
            }
            answer += right - left + 1;
        }
        return answer;
    }
};
