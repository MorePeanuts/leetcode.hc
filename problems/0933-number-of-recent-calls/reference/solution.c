typedef struct {
    int times[10000];
    int head;
    int tail;
} RecentCounter;

RecentCounter *recentCounterCreate(void) {
    RecentCounter *obj = malloc(sizeof(*obj));
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

int recentCounterPing(RecentCounter *obj, int t) {
    obj->times[obj->tail++] = t;
    while (obj->times[obj->head] < t - 3000) {
        obj->head++;
    }
    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter *obj) {
    free(obj);
}
