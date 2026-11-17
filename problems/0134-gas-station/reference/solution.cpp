class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total = 0;
        int tank = 0;
        for (int i = 0; i < static_cast<int>(gas.size()); i++) {
            int net = gas[i] - cost[i];
            total += net;
            tank += net;
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        return total >= 0 ? start : -1;
    }
};
