class Solution {
    void visit(TreeNode* node, std::string path, std::vector<std::string>& result) {
        if (node == nullptr) {
            return;
        }
        if (!path.empty()) {
            path += "->";
        }
        path += std::to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(std::move(path));
            return;
        }
        visit(node->left, path, result);
        visit(node->right, path, result);
    }

public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> result;
        visit(root, "", result);
        return result;
    }
};
