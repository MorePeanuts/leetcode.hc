class Solution {
public:
    Node * connect(Node * root) {
        Node * level = root;
        while (level != nullptr) {
            Node dummy{};
            Node * tail = &dummy;
            Node * node = level;
            while (node != nullptr) {
                if (node->left != nullptr) {
                    tail->next = node->left;
                    tail = tail->next;
                }
                if (node->right != nullptr) {
                    tail->next = node->right;
                    tail = tail->next;
                }
                node = node->next;
            }
            level = dummy.next;
        }
        return root;
    }
};
