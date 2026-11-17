function maxProfit(prices) {
    const n = prices.length;
    let hold = -prices[0];
    let sold = 0;
    let rest = 0;
    for (let i = 1; i < n; i++) {
        let price = prices[i];
        let previousHold = hold;
        let previousSold = sold;
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
