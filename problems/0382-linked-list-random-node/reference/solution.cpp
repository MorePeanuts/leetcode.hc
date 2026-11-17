#include <random>

class Solution {
    ListNode* head;
    std::mt19937 rng{std::random_device{}()};

public:
    Solution(ListNode* head) : head(head) {}

    int getRandom() {
        int result = head->val;
        int count = 0;
        for (auto* node = head; node != nullptr; node = node->next) {
            if (std::uniform_int_distribution<int>(0, count++)(rng) == 0) {
                result = node->val;
            }
        }
        return result;
    }
};
