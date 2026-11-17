function wordBreak(s: string, wordDict: string[]): boolean {
    const words = new Set(wordDict);
    let longest = 0;
    for (const word of wordDict) longest = Math.max(longest, word.length);
    const possible = new Uint8Array(s.length + 1);
    possible[0] = 1;
    for (let end = 1; end <= s.length; end++) {
        for (let start = Math.max(0, end - longest); start < end; start++) {
            if (possible[start] && words.has(s.slice(start, end))) {
                possible[end] = 1;
                break;
            }
        }
    }
    return possible[s.length] === 1;
}
