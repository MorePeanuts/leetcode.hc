function preorder(root: _Node | null): number[] {
    if (root === null) return [];
    const stack = [root];
    const result: number[] = [];
    while (stack.length > 0) {
        const node = stack.pop()!;
        result.push(node.val);
        for (let i = node.children.length - 1; i >= 0; i--) {
            stack.push(node.children[i]);
        }
    }
    return result;
}
