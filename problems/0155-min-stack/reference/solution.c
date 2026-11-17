#include <stdlib.h>

typedef struct {
    int value;
    int minimum;
} Entry;

typedef struct {
    Entry* entries;
    size_t size;
    size_t capacity;
} MinStack;

MinStack* minStackCreate(void) {
    return calloc(1, sizeof(MinStack));
}

void minStackPush(MinStack* stack, int value) {
    if (stack->size == stack->capacity) {
        stack->capacity = stack->capacity ? 2 * stack->capacity : 8;
        stack->entries = realloc(stack->entries, stack->capacity * sizeof(*stack->entries));
    }
    int minimum = value;
    if (stack->size > 0 && stack->entries[stack->size - 1].minimum < value)
        minimum = stack->entries[stack->size - 1].minimum;
    stack->entries[stack->size++] = (Entry){value, minimum};
}

void minStackPop(MinStack* stack) {
    stack->size--;
}

int minStackTop(MinStack* stack) {
    return stack->entries[stack->size - 1].value;
}

int minStackGetMin(MinStack* stack) {
    return stack->entries[stack->size - 1].minimum;
}

void minStackFree(MinStack* stack) {
    free(stack->entries);
    free(stack);
}
