class StockSpanner {
    private readonly quotes: [number, number][] = [];

    next(price: number): number {
        let span = 1;
        while (this.quotes.length > 0 && this.quotes[this.quotes.length - 1][0] <= price) {
            span += this.quotes.pop()![1];
        }
        this.quotes.push([price, span]);
        return span;
    }
}
