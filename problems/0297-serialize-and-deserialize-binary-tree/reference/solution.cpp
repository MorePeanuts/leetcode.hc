#include <cstdlib>
#include <queue>
#include <string>

class Codec {
    static TreeNode* readNode(const char*& next) {
        if (*next == '#') {
            next += 2;
            return nullptr;
        }
        char* end;
        int value = static_cast<int>(std::strtol(next, &end, 10));
        next = end + 1;
        return new TreeNode(value);
    }

public:
    std::string serialize(TreeNode* root) {
        std::string data;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node) {
                data += std::to_string(node->val);
                queue.push(node->left);
                queue.push(node->right);
            } else {
                data += '#';
            }
            data += ',';
        }
        return data;
    }

    TreeNode* deserialize(std::string data) {
        const char* next = data.c_str();
        TreeNode* root = readNode(next);
        if (!root) return nullptr;

        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* parent = queue.front();
            queue.pop();
            parent->left = readNode(next);
            parent->right = readNode(next);
            if (parent->left) queue.push(parent->left);
            if (parent->right) queue.push(parent->right);
        }
        return root;
    }
};
