class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        vector<Node *> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            Node *node = stack.back();
            stack.pop_back();
            result.push_back(node->val);
            for (Node *child : node->children) {
                stack.push_back(child);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
