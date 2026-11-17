function lengthOfLongestSubstring(s) {
    const last = new Int32Array(128);
    let start = 0;
    let best = 0;
    for (let i = 0; i < s.length; i++) {
        const ch = s.charCodeAt(i);
        start = Math.max(start, last[ch]);
        last[ch] = i + 1;
        best = Math.max(best, i + 1 - start);
    }
    return best;
}
