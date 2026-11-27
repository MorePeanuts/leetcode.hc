class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int previousCount = 0, singles = 0, pairs = 0;
        for (int start = 0; start < n; ) {
            if (start > 0 && nums[start] != nums[start - 1] + 1) {
                if (singles + pairs > 0) return false;
                previousCount = 0;
            }
            int end = start + 1;
            while (end < n && nums[end] == nums[start]) end++;
            int count = end - start;

            // Every short sequence must receive a copy before longer ones can extend.
            if (count < singles + pairs) return false;
            pairs = singles;
            singles = count > previousCount ? count - previousCount : 0;
            previousCount = count;
            start = end;
        }
        return singles + pairs == 0;
    }
};
