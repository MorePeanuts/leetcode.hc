function evalRPN(tokens: string[]): number {
    const stack = new Int32Array(tokens.length);
    let size = 0;
    for (let i = 0; i < tokens.length; ++i) {
        let op = tokens[i].charCodeAt(0);
        if (tokens[i].length === 1 && (op === 43 || op === 45 || op === 42 || op === 47)) {
            let right = stack[--size];
            let left = stack[--size];
            if (op === 43) {
                stack[size++] = left + right;
            } else if (op === 45) {
                stack[size++] = left - right;
            } else if (op === 42) {
                stack[size++] = left * right;
            } else {
                stack[size++] = Math.trunc(left / right);
            }
        } else {
            stack[size++] = Number(tokens[i]);
        }
    }
    let answer = stack[0];
    return answer;
}
