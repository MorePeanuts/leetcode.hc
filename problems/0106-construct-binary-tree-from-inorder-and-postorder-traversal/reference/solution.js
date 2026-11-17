function buildTree(inorder, postorder) {
    const n = inorder.length;
    let root = new TreeNode(postorder[n - 1]);
    const stack = [];
    stack.push(root);
    let index = n - 1;
    for (let i = n - 2; i >= 0; i--) {
        let node = stack[stack.length - 1];
        let child = new TreeNode(postorder[i]);
        if (node.val !== inorder[index]) {
            node.right = child;
        } else {
            while (stack.length > 0 && stack[stack.length - 1].val === inorder[index]) {
                node = stack.pop();
                index--;
            }
            node.left = child;
        }
        stack.push(child);
    }
    return root;
}
