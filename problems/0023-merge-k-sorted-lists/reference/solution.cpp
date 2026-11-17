class Solution {
    static ListNode *mergeTwo(ListNode *a, ListNode *b) {
        ListNode dummy;
        ListNode *tail = &dummy;
        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a != nullptr ? a : b;
        return dummy.next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();

        for (int step = 1; step < n; step *= 2) {
            for (int i = 0; i + step < n; i += 2 * step) {
                lists[i] = mergeTwo(lists[i], lists[i + step]);
            }
        }
        return n == 0 ? nullptr : lists[0];
    }
};
