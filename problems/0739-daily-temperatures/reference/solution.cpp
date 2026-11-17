class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        vector<int> stack(n);
        int size = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (size > 0 && temperatures[stack[size - 1]] <= temperatures[i]) {
                size--;
            }
            result[i] = size == 0 ? 0 : stack[size - 1] - i;
            stack[size++] = i;
        }
        return result;
    }
};
