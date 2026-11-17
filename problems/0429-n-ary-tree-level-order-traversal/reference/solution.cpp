#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        std::vector<Node*> queue{root};
        std::vector<std::vector<int>> result;
        for (size_t head = 0; head < queue.size();) {
            const size_t end = queue.size();
            auto& level = result.emplace_back();
            for (; head < end; head++) {
                Node* node = queue[head];
                level.push_back(node->val);
                queue.insert(queue.end(), node->children.begin(), node->children.end());
            }
        }
        return result;
    }
};
