class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;
        for (int i = 1; i < n; i++) {
            int price = prices[i];
            int previousHold = hold;
            int previousSold = sold;
            if (rest - price > hold) {
                hold = rest - price;
            }
            sold = previousHold + price;
            if (previousSold > rest) {
                rest = previousSold;
            }
        }
        return sold > rest ? sold : rest;
    }
};
