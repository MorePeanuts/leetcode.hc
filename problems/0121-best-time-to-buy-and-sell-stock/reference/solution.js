function maxProfit(prices) {
    let lowest = prices[0];
    let best = 0;
    for (const price of prices) {
        if (price < lowest) lowest = price;
        else if (price - lowest > best) best = price - lowest;
    }
    return best;
}
