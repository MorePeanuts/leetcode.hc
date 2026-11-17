class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row = 0;
        int col = static_cast<int>(matrix[0].size()) - 1;
        while (row < static_cast<int>(matrix.size()) && col >= 0) {
            int value = matrix[row][col];
            if (value == target) {
                return true;
            }
            if (value > target) {
                --col;
            } else {
                ++row;
            }
        }
        return false;
    }
};
