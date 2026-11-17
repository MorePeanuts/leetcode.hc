class Solution {
    static ListNode * splitRun(ListNode * node, int size) {
    if (node == nullptr) {
            return nullptr;
        }
        for (int i = 1; i < size && node->next != nullptr; i++) {
            node = node->next;
        }
        ListNode * rest = node->next;
        node->next = nullptr;
        return rest;
    }

public:
    ListNode * sortList(ListNode * head) {
        int length = 0;
        ListNode * node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode dummy{};
        ListNode * sentinel = &dummy;
        sentinel->next = head;
        for (int width = 1; width < length; width *= 2) {
            ListNode * tail = sentinel;
            ListNode * current = sentinel->next;
            while (current != nullptr) {
                ListNode * left = current;
                ListNode * right = splitRun(left, width);
                current = splitRun(right, width);
                while (left != nullptr && right != nullptr) {
                    if (left->val <= right->val) {
                        tail->next = left;
                        left = left->next;
                    } else {
                        tail->next = right;
                        right = right->next;
                    }
                    tail = tail->next;
                }
                tail->next = left != nullptr ? left : right;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }
            }
        }
        return sentinel->next;
    }
};
