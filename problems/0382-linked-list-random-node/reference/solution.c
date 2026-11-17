#include <time.h>

typedef struct {
    struct ListNode* head;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = malloc(sizeof(*obj));
    obj->head = head;
    struct timespec now;
    if (timespec_get(&now, TIME_UTC) == TIME_UTC) {
        srand((unsigned)now.tv_sec ^ (unsigned)now.tv_nsec);
    }
    return obj;
}

int solutionGetRandom(Solution* obj) {
    int result = obj->head->val;
    unsigned count = 0;
    for (struct ListNode* node = obj->head; node != NULL; node = node->next) {
        ++count;
        unsigned range = (unsigned)RAND_MAX + 1U;
        unsigned bound = range - range % count;
        unsigned draw;
        // Discard the partial bucket so each index has exactly equal weight.
        do {
            draw = (unsigned)rand();
        } while (draw >= bound);
        if (draw % count == 0) {
            result = node->val;
        }
    }
    return result;
}

void solutionFree(Solution* obj) {
    free(obj);
}
