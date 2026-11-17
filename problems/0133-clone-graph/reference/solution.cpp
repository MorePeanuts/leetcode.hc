class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> copies{{node, new Node(node->val)}};
        std::queue<Node*> queue;
        queue.push(node);
        while (!queue.empty()) {
            auto* current = queue.front();
            queue.pop();
            auto* copy = copies.at(current);
            for (auto* neighbor : current->neighbors) {
                auto [entry, inserted] = copies.emplace(neighbor, nullptr);
                if (inserted) {
                    entry->second = new Node(neighbor->val);
                    queue.push(neighbor);
                }
                copy->neighbors.push_back(entry->second);
            }
        }
        return copies.at(node);
    }
};
