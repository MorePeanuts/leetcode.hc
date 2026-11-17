#include <vector>

class MyCircularQueue {
    std::vector<int> data;
    int head = 0;
    int size = 0;
    int capacity;

public:
    explicit MyCircularQueue(int k) : data(k), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        data[(head + size) % capacity] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        size--;
        return true;
    }

    int Front() { return isEmpty() ? -1 : data[head]; }
    int Rear() { return isEmpty() ? -1 : data[(head + size - 1) % capacity]; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
};
