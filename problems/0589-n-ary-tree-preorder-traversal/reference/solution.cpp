#include <vector>

class Solution {
public:
    std::vector<int> preorder(Node* root) {
        if (!root) return {};
        std::vector<Node*> stack{root};
        std::vector<int> result;
        while (!stack.empty()) {
            Node* node = stack.back();
            stack.pop_back();
            result.push_back(node->val);
            stack.insert(stack.end(), node->children.rbegin(), node->children.rend());
        }
        return result;
    }
};
