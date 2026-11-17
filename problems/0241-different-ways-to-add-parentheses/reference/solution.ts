function diffWaysToCompute(expression: string): number[] {
    const memo = new Map<string, number[]>();
    function solve(text: string): number[] {
        const known = memo.get(text);
        if (known !== undefined) return known;
        const output: number[] = [];
        for (let i = 0; i < text.length; i++) {
            const op = text[i];
            if (op !== '+' && op !== '-' && op !== '*') continue;
            const left = solve(text.slice(0, i));
            const right = solve(text.slice(i + 1));
            for (const a of left)
                for (const b of right)
                    output.push(op === '+' ? a + b : op === '-' ? a - b : a * b);
        }
        if (output.length === 0) output.push(Number(text));
        memo.set(text, output);
        return output;
    }
    return solve(expression);
}
