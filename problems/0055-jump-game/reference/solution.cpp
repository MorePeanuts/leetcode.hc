class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i <= farthest; ++i) {
            if (i + nums[i] > farthest) {
                farthest = i + nums[i];
            }
            if (farthest >= static_cast<int>(nums.size()) - 1) {
                return true;
            }
        }
        return false;
    }
};
