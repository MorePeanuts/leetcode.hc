class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (auto* node = head; node != nullptr; node = node->next->next) {
            auto* copy = new Node(node->val);
            copy->next = node->next;
            node->next = copy;
        }
        for (auto* node = head; node != nullptr; node = node->next->next) {
            node->next->random = node->random == nullptr ? nullptr : node->random->next;
        }
        auto* result = head->next;
        for (auto* node = head; node != nullptr; node = node->next) {
            auto* copy = node->next;
            node->next = copy->next;
            copy->next = node->next == nullptr ? nullptr : node->next->next;
        }
        return result;
    }
};
