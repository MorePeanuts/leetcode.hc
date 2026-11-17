function letterCombinations(digits: string): string[] {
    const keypad = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
    let result = [""];
    for (const digit of digits) {
        const next: string[] = [];
        for (const prefix of result) {
            for (const letter of keypad[Number(digit) - 2]) {
                next.push(prefix + letter);
            }
        }
        result = next;
    }
    return result;
}
