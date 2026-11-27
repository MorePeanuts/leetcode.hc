function longestSubstring(s: string, k: number): number {
    function longestRange(begin: number, end: number): number {
        if (end - begin < k) return 0;
        const counts = new Int32Array(26);
        for (let i = begin; i < end; i++) {
            counts[s.charCodeAt(i) - 97]++;
        }
        let start = begin, best = 0;
        for (let i = begin; i < end; i++) {
            if (counts[s.charCodeAt(i) - 97] < k) {
                if (i - start >= k) {
                    const length = longestRange(start, i);
                    if (length > best) best = length;
                }
                start = i + 1;
            }
        }
        if (start === begin) return end - begin;
        const tail = longestRange(start, end);
        return tail > best ? tail : best;
    }
    return longestRange(0, s.length);
}
