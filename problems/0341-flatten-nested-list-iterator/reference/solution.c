struct IteratorFrame {
    struct NestedInteger **list;
    int size;
    int index;
};

struct NestedIterator {
    struct IteratorFrame *frames;
    size_t depth;
    size_t capacity;
};

static void pushList(struct NestedIterator *iter, struct NestedInteger **list, int size) {
    if (iter->depth == iter->capacity) {
        size_t capacity = iter->capacity == 0 ? 8 : iter->capacity * 2;
        struct IteratorFrame *frames = realloc(iter->frames, capacity * sizeof(*frames));
        if (frames == NULL) {
            abort();
        }
        iter->frames = frames;
        iter->capacity = capacity;
    }
    // The input owns each list for the lifetime of the iterator.
    iter->frames[iter->depth++] = (struct IteratorFrame){list, size, 0};
}

struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList, int nestedListSize) {
    struct NestedIterator *iter = malloc(sizeof(*iter));
    if (iter == NULL) {
        abort();
    }
    *iter = (struct NestedIterator){0};
    pushList(iter, nestedList, nestedListSize);
    return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    while (iter->depth > 0) {
        struct IteratorFrame *frame = &iter->frames[iter->depth - 1];
        if (frame->index == frame->size) {
            --iter->depth;
            continue;
        }

        struct NestedInteger *value = frame->list[frame->index];
        if (NestedIntegerIsInteger(value)) {
            return true;
        }
        ++frame->index;
        pushList(iter, NestedIntegerGetList(value), NestedIntegerGetListSize(value));
    }
    return false;
}

int nestedIterNext(struct NestedIterator *iter) {
    if (!nestedIterHasNext(iter)) {
        abort();
    }
    struct IteratorFrame *frame = &iter->frames[iter->depth - 1];
    return NestedIntegerGetInteger(frame->list[frame->index++]);
}

void nestedIterFree(struct NestedIterator *iter) {
    free(iter->frames);
    free(iter);
}
