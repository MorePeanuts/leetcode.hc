#include <stdlib.h>

typedef struct Item {
    int value;
    struct Item* next;
} Item;

typedef struct {
    Item head;
    Item* tail;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate(void) {
    MyLinkedList* list = calloc(1, sizeof(*list));
    list->tail = &list->head;
    return list;
}

static Item* before(MyLinkedList* list, int index) {
    Item* node = &list->head;
    while (index-- > 0) node = node->next;
    return node;
}

int myLinkedListGet(MyLinkedList* list, int index) {
    return index >= 0 && index < list->size ? before(list, index)->next->value : -1;
}

void myLinkedListAddAtIndex(MyLinkedList* list, int index, int val) {
    if (index < 0 || index > list->size) return;
    Item* previous = index == list->size ? list->tail : before(list, index);
    Item* node = malloc(sizeof(*node));
    *node = (Item){val, previous->next};
    previous->next = node;
    if (index == list->size) list->tail = node;
    list->size++;
}

void myLinkedListAddAtHead(MyLinkedList* list, int val) { myLinkedListAddAtIndex(list, 0, val); }
void myLinkedListAddAtTail(MyLinkedList* list, int val) { myLinkedListAddAtIndex(list, list->size, val); }

void myLinkedListDeleteAtIndex(MyLinkedList* list, int index) {
    if (index < 0 || index >= list->size) return;
    Item* previous = before(list, index);
    Item* removed = previous->next;
    previous->next = removed->next;
    if (removed == list->tail) list->tail = previous;
    list->size--;
    free(removed);
}

void myLinkedListFree(MyLinkedList* list) {
    Item* node = list->head.next;
    while (node) {
        Item* next = node->next;
        free(node);
        node = next;
    }
    free(list);
}
