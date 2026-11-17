function isValid(s) {
    const n = s.length;
    const stack = [];

    let size = 0;
    for (let i = 0; i < n; i++) {
        const c = s[i];
        switch (c) {
            case '(':
                stack[size++] = ')';
                break;
            case '[':
                stack[size++] = ']';
                break;
            case '{':
                stack[size++] = '}';
                break;
            default:
                if (size === 0 || stack[--size] !== c) {
                    return false;
                }
        }
    }
    return size === 0;
}
