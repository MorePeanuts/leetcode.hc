function isAnagram(s: string, t: string): boolean {
    const m = s.length;
    const n = t.length;
    if (m !== n) {
        return false;
    }
    const counts = new Int32Array(26);
    for (let i = 0; i < n; i++) {
        counts[s.charCodeAt(i) - 97]++;
        counts[t.charCodeAt(i) - 97]--;
    }
    for (let i = 0; i < 26; i++) {
        if (counts[i] !== 0) {
            return false;
        }
    }
    return true;
}
