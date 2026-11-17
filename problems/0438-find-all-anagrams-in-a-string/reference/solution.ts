function findAnagrams(s: string, p: string): number[] {
    let n = s.length;
    let m = p.length;
    const need = new Int32Array(26);
    const window = new Int32Array(26);
    const result: number[] = [];
    for (let i = 0; i < m; i++) need[p.charCodeAt(i) - 97]++;
    for (let right = 0; right < n; right++) {
        window[s.charCodeAt(right) - 97]++;
        if (right >= m) window[s.charCodeAt(right - m) - 97]--;
        if (right + 1 >= m && window.every((count, i) => count === need[i])) result.push(right + 1 - m);
    }
    return result;
}
