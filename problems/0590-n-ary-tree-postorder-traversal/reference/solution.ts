function postorder(root: _Node | null): number[] {
    const result: number[] = [];
    if (root === null) {
        return result;
    }
    const stack: _Node[] = [];
    stack.push(root);
    while (stack.length > 0) {
        const node = stack.pop()!;
        result.push(node.val);
        for (const child of node.children) {
            stack.push(child);
        }
    }
    result.reverse();
    return result;
}
