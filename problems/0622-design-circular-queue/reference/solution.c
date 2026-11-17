#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int head;
    int size;
    int data[];
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = malloc(sizeof(*queue) + (size_t)k * sizeof(*queue->data));
    queue->capacity = k;
    queue->head = queue->size = 0;
    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* queue) { return queue->size == 0; }
bool myCircularQueueIsFull(MyCircularQueue* queue) { return queue->size == queue->capacity; }

bool myCircularQueueEnQueue(MyCircularQueue* queue, int value) {
    if (myCircularQueueIsFull(queue)) return false;
    int index = (queue->head + queue->size) % queue->capacity;
    queue->data[index] = value;
    queue->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* queue) {
    if (myCircularQueueIsEmpty(queue)) return false;
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* queue) {
    return myCircularQueueIsEmpty(queue) ? -1 : queue->data[queue->head];
}

int myCircularQueueRear(MyCircularQueue* queue) {
    if (myCircularQueueIsEmpty(queue)) return -1;
    return queue->data[(queue->head + queue->size - 1) % queue->capacity];
}

void myCircularQueueFree(MyCircularQueue* queue) { free(queue); }
