#include <stdlib.h>

typedef struct { int value, index; } Query;
typedef struct { int length, end; } Interval;

static int compareIntervals(const void* lhs, const void* rhs) {
    int a = (*(int* const*)lhs)[0];
    int b = (*(int* const*)rhs)[0];
    return (a > b) - (a < b);
}

static int compareQueries(const void* lhs, const void* rhs) {
    int a = ((const Query*)lhs)->value;
    int b = ((const Query*)rhs)->value;
    return (a > b) - (a < b);
}

static void push(Interval* heap, int size, Interval entry) {
    int i = size;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].length <= entry.length) break;
        heap[i] = heap[parent];
        i = parent;
    }
    heap[i] = entry;
}

static void pop(Interval* heap, int size) {
    Interval entry = heap[size];
    int i = 0;
    for (int child = 1; child < size; child = 2 * i + 1) {
        if (child + 1 < size && heap[child + 1].length < heap[child].length) child++;
        if (entry.length <= heap[child].length) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = entry;
}

int* minInterval(int** intervals, int intervalsSize, int* intervalsColSize,
                 int* queries, int queriesSize, int* returnSize) {
    Query* order = malloc((size_t)queriesSize * sizeof(*order));
    Interval* heap = malloc((size_t)intervalsSize * sizeof(*heap));
    int* answer = malloc((size_t)queriesSize * sizeof(*answer));
    for (int i = 0; i < queriesSize; i++) order[i] = (Query){queries[i], i};
    qsort(order, queriesSize, sizeof(*order), compareQueries);
    qsort(intervals, intervalsSize, sizeof(*intervals), compareIntervals);

    int size = 0;
    int next = 0;
    for (int i = 0; i < queriesSize; i++) {
        Query query = order[i];
        while (next < intervalsSize && intervals[next][0] <= query.value) {
            int* interval = intervals[next++];
            push(heap, size++, (Interval){interval[1] - interval[0] + 1, interval[1]});
        }
        while (size > 0 && heap[0].end < query.value) pop(heap, --size);
        answer[query.index] = size > 0 ? heap[0].length : -1;
    }
    free(heap);
    free(order);
    *returnSize = queriesSize;
    return answer;
}
