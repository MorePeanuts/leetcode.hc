import java.util.ArrayDeque;
import java.util.Deque;

class StockSpanner {
    private record Quote(int price, int span) {}
    private final Deque<Quote> quotes = new ArrayDeque<>();

    public int next(int price) {
        int span = 1;
        while (!quotes.isEmpty() && quotes.peek().price() <= price) {
            span += quotes.pop().span();
        }
        quotes.push(new Quote(price, span));
        return span;
    }
}
