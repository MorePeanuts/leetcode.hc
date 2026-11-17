class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int low = 0;
        int high = rows * columns - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = matrix[mid / columns][mid % columns];
            if (value == target) {
                return true;
            }
            if (value < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};
