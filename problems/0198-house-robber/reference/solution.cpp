class Solution {
public:
    int rob(vector<int>& nums) {
        int previous = 0;
        int current = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int take = previous + nums[i];
            previous = current;
            if (take > current) current = take;
        }
        return current;
    }
};
