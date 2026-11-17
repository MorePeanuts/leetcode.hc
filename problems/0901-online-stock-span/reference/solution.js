class StockSpanner {
    constructor() {
        this.quotes = [];
    }

    next(price) {
        let span = 1;
        while (this.quotes.length > 0 && this.quotes[this.quotes.length - 1][0] <= price) {
            span += this.quotes.pop()[1];
        }
        this.quotes.push([price, span]);
        return span;
    }
}
