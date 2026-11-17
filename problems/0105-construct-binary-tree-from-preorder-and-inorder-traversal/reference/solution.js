function buildTree(preorder, inorder) {
    let root = new TreeNode(preorder[0]);
    const stack = [];
    stack[0] = root;
    let count = 1;
    let j = 0;
    for (let i = 1; i < preorder.length; i++) {
        let node = new TreeNode(preorder[i]);
        let parent = stack[count - 1];
        if (parent.val !== inorder[j]) {
            parent.left = node;
        } else {
            while (count > 0 && stack[count - 1].val === inorder[j]) {
                parent = stack[--count];
                j++;
            }
            parent.right = node;
        }
        stack[count++] = node;
    }
    return root;
}
