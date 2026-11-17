function restoreIpAddresses(s: string): string[] {
    const result: string[] = [];

    function visit(start: number, count: number, path: string): void {
        let left = 4 - count;
        if (s.length - start < left || s.length - start > 3 * left) {
            return;
        }
        if (left === 0) {
            result.push(path);
            return;
        }
        let value = 0;
        for (let length = 1; length <= 3 && start + length <= s.length; ++length) {
            value = value * 10 + Number(s[start + length - 1]);
            if (value > 255 || (length > 1 && s[start] === "0")) {
                break;
            }
            const next = path + (count === 0 ? "" : ".") + s.slice(start, start + length);
            visit(start + length, count + 1, next);
        }
    }

    visit(0, 0, "");
    return result;
}
