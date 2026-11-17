class MyLinkedList {
    struct Item {
        int value;
        Item* next;
    };
    Item head{0, nullptr};
    Item* tail = &head;
    int size = 0;

    Item* before(int index) {
        auto* node = &head;
        while (index-- > 0) node = node->next;
        return node;
    }

public:
    int get(int index) {
        return index >= 0 && index < size ? before(index)->next->value : -1;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        auto* previous = index == size ? tail : before(index);
        auto* node = new Item{val, previous->next};
        previous->next = node;
        if (index == size) tail = node;
        size++;
    }

    void addAtHead(int val) { addAtIndex(0, val); }
    void addAtTail(int val) { addAtIndex(size, val); }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        auto* previous = before(index);
        auto* removed = previous->next;
        previous->next = removed->next;
        if (removed == tail) tail = previous;
        size--;
        delete removed;
    }

    ~MyLinkedList() {
        while (head.next) {
            auto* removed = head.next;
            head.next = removed->next;
            delete removed;
        }
    }
};
