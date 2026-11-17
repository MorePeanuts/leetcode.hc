function change(amount, coins) {
    const ways = new Int32Array(amount + 1);
    ways[0] = 1;
    for (let i = 0; i < coins.length; i++) {
        let coin = coins[i];
        for (let total = coin; total <= amount; total++) {
            ways[total] = Math.min(2147483647, ways[total] + ways[total - coin]);
        }
    }
    return ways[amount];
}
