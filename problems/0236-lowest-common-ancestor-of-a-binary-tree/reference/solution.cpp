class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::unordered_map<TreeNode*, TreeNode*> parents{{root, nullptr}};
        std::unordered_set<TreeNode*> ancestors;
        std::vector<TreeNode*> stack{root};
        while (!stack.empty()) {
            auto* node = stack.back();
            stack.pop_back();

            for (auto* child : {node->left, node->right}) {
                if (child != nullptr) {
                    parents.emplace(child, node);
                    stack.push_back(child);
                }
            }
        }
        while (p != nullptr) {
            ancestors.insert(p);
            p = parents.at(p);
        }
        while (!ancestors.count(q)) {
            q = parents.at(q);
        }
        return q;
    }
};
