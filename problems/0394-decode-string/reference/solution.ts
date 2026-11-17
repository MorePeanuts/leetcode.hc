function decodeString(s: string): string {
    const stack: { prefix: string; repeat: number }[] = [];
    let current = "";
    let repeat = 0;
    for (const ch of s) {
        if (ch >= '0' && ch <= '9') {
            repeat = repeat * 10 + Number(ch);
        } else if (ch === '[') {
            stack.push({ prefix: current, repeat });
            current = "";
            repeat = 0;
        } else if (ch === ']') {
            const frame = stack.pop()!;
            current = frame.prefix + current.repeat(frame.repeat);
        } else {
            current += ch;
        }
    }
    return current;
}
