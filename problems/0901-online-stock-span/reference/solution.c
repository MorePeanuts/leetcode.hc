typedef struct {
    int price;
    int span;
} Quote;

typedef struct {
    Quote* quotes;
    int size;
    int capacity;
} StockSpanner;

StockSpanner* stockSpannerCreate(void) {
    return calloc(1, sizeof(StockSpanner));
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while (obj->size > 0 && obj->quotes[obj->size - 1].price <= price) {
        span += obj->quotes[--obj->size].span;
    }
    if (obj->size == obj->capacity) {
        obj->capacity = obj->capacity == 0 ? 8 : obj->capacity * 2;
        obj->quotes = realloc(obj->quotes, (size_t)obj->capacity * sizeof(*obj->quotes));
    }
    obj->quotes[obj->size++] = (Quote){price, span};
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->quotes);
    free(obj);
}
