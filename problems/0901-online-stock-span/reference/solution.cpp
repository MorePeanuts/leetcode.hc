class StockSpanner {
    std::vector<std::pair<int, int>> quotes;

public:
    int next(int price) {
        int span = 1;
        while (!quotes.empty() && quotes.back().first <= price) {
            span += quotes.back().second;
            quotes.pop_back();
        }
        quotes.emplace_back(price, span);
        return span;
    }
};
