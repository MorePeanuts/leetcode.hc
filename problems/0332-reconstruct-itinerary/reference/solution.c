#include <stdlib.h>
#include <string.h>

static int airport(const char* name) {
    return (name[0] - 'A') * 676 + (name[1] - 'A') * 26 + (name[2] - 'A');
}

static int compare(const void* lhs, const void* rhs) {
    char** a = *(char** const*)lhs;
    char** b = *(char** const*)rhs;
    int from = strcmp(a[0], b[0]);
    return from ? from : strcmp(b[1], a[1]);
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    // Store each origin's unconsumed range in the sorted ticket list.
    int starts[26 * 26 * 26] = {0};
    int ends[26 * 26 * 26] = {0};
    qsort(tickets, ticketsSize, sizeof(*tickets), compare);
    for (int i = 0; i < ticketsSize; i++) {
        int index = airport(tickets[i][0]);
        if (ends[index] == 0) starts[index] = i;
        ends[index] = i + 1;
    }
    char* stack[301];
    stack[0] = "JFK";
    int count = 1;
    int write = ticketsSize;
    char** result = malloc((size_t)(ticketsSize + 1) * sizeof(*result));
    while (count > 0) {
        char* from = stack[count - 1];
        int index = airport(from);
        if (ends[index] > starts[index]) {
            stack[count++] = tickets[--ends[index]][1];
        } else {
            result[write--] = stack[--count];
        }
    }
    *returnSize = ticketsSize + 1;
    return result;
}
