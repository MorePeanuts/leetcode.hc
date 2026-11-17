class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int write = 0;
        for (int read = 0; read < static_cast<int>(nums.size()); ++read) {
            if (nums[read] != 0) {
                int temp = nums[write];
                nums[write] = nums[read];
                nums[read] = temp;
                ++write;
            }
        }
    }
};
