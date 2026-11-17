function generateParenthesis(n) {
    const result = [];
    const path = [];
    function generate(opened, closed) {
        if (closed === n) {
            result.push(path.join(""));
            return;
        }
        const index = opened + closed;
        if (opened < n) {
            path[index] = "(";
            generate(opened + 1, closed);
        }
        if (closed < opened) {
            path[index] = ")";
            generate(opened, closed + 1);
        }
    }
    generate(0, 0);
    return result;
}
