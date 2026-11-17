function firstUniqChar(s) {
    const n = s.length;
    const counts = new Int32Array(26);
    for (let i = 0; i < n; i++) {
        counts[s.charCodeAt(i) - 97]++;
    }
    for (let i = 0; i < n; i++) {
        if (counts[s.charCodeAt(i) - 97] === 1) {
            return i;
        }
    }
    return -1;
}
