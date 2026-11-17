function postorderTraversal(root) {
    const result = [];
    function visit(node) {
        if (node === null) {
            return;
        }
        visit(node.left);
        visit(node.right);
        result.push(node.val);
    }
    visit(root);
    return result;
}
