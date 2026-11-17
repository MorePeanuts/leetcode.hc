#include <stdlib.h>
#include "uthash.h"

typedef struct Point {
    int key;
    int y;
    int count;
    struct Point* next;
    UT_hash_handle hh;
} Point;

typedef struct {
    Point* points;
    Point* columns[1001];
} DetectSquares;

DetectSquares* detectSquaresCreate(void) {
    return calloc(1, sizeof(DetectSquares));
}

void detectSquaresAdd(DetectSquares* obj, int* point, int pointSize) {
    int x = point[0], y = point[1];
    int key = 1001 * x + y;
    Point* entry;
    HASH_FIND_INT(obj->points, &key, entry);
    if (entry) {
        entry->count++;
    } else {
        entry = malloc(sizeof(*entry));
        entry->key = key;
        entry->y = y;
        entry->count = 1;
        entry->next = obj->columns[x];
        obj->columns[x] = entry;
        HASH_ADD_INT(obj->points, key, entry);
    }
}

static int frequency(DetectSquares* obj, int x, int y) {
    if (x < 0 || x > 1000) return 0;
    int key = 1001 * x + y;
    Point* entry;
    HASH_FIND_INT(obj->points, &key, entry);
    return entry ? entry->count : 0;
}

int detectSquaresCount(DetectSquares* obj, int* point, int pointSize) {
    int x = point[0], y = point[1];
    int result = 0;
    for (Point* entry = obj->columns[x]; entry; entry = entry->next) {
        int otherY = entry->y;
        int side = otherY - y;
        if (side == 0) continue;
        result += entry->count * (
            frequency(obj, x - side, y) * frequency(obj, x - side, otherY) +
            frequency(obj, x + side, y) * frequency(obj, x + side, otherY));
    }
    return result;
}

void detectSquaresFree(DetectSquares* obj) {
    Point* entry;
    Point* next;
    HASH_ITER(hh, obj->points, entry, next) {
        HASH_DEL(obj->points, entry);
        free(entry);
    }
    free(obj);
}
