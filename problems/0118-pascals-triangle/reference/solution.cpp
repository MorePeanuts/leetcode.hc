class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> rows;
        for (int row = 0; row < numRows; ++row) {
            std::vector<int> next(row + 1, 1);
            for (int col = 1; col < row; ++col) {
                next[col] = rows.back()[col - 1] + rows.back()[col];
            }
            rows.push_back(std::move(next));
        }
        return rows;
    }
};
