function checkInclusion(s1: string, s2: string): boolean {
    const m = s1.length;
    const n = s2.length;
    if (m > n) {
        return false;
    }
    const diff = new Int32Array(26);
    for (let i = 0; i < m; i++) {
        diff[s1.charCodeAt(i) - 97]--;
        diff[s2.charCodeAt(i) - 97]++;
    }
    let nonzero = 0;
    for (let i = 0; i < 26; i++) {
        if (diff[i] !== 0) {
            nonzero++;
        }
    }
    if (nonzero === 0) {
        return true;
    }
    for (let i = m; i < n; i++) {
        let entering = s2.charCodeAt(i) - 97;
        let leaving = s2.charCodeAt(i - m) - 97;
        if (entering === leaving) {
            continue;
        }
        if (diff[entering] === 0) {
            nonzero++;
        }
        diff[entering]++;
        if (diff[entering] === 0) {
            nonzero--;
        }
        if (diff[leaving] === 0) {
            nonzero++;
        }
        diff[leaving]--;
        if (diff[leaving] === 0) {
            nonzero--;
        }
        if (nonzero === 0) {
            return true;
        }
    }
    return false;
}
