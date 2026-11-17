class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        TreeNode * root = new TreeNode(postorder[n - 1]);
        vector<TreeNode *> stack;
        stack.push_back(root);
        int index = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            TreeNode * node = stack.back();
            TreeNode * child = new TreeNode(postorder[i]);
            if (node->val != inorder[index]) {
                node->right = child;
            } else {
                while (!stack.empty() && stack.back()->val == inorder[index]) {
                    node = stack.back();
                    stack.pop_back();
                    index--;
                }
                node->left = child;
            }
            stack.push_back(child);
        }
        return root;
    }
};
