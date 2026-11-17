class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int value = nums[i];
            if (length < 2 || value != nums[length - 2]) {
                nums[length] = value;
                length++;
            }
        }
        return length;
    }
};
