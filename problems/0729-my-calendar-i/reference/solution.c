#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int start, end; } Event;
typedef struct {
    Event events[1000];
    int size;
} MyCalendar;

MyCalendar* myCalendarCreate(void) {
    MyCalendar* obj = malloc(sizeof(*obj));
    obj->size = 0;
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int startTime, int endTime) {
    int lo = 0, hi = obj->size;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (obj->events[mid].start < startTime) lo = mid + 1;
        else hi = mid;
    }
    if (lo > 0 && obj->events[lo - 1].end > startTime) return false;
    if (lo < obj->size && obj->events[lo].start < endTime) return false;
    memmove(obj->events + lo + 1, obj->events + lo, (size_t)(obj->size - lo) * sizeof(Event));
    obj->events[lo] = (Event){startTime, endTime};
    obj->size++;
    return true;
}

void myCalendarFree(MyCalendar* obj) { free(obj); }
