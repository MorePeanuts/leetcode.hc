function partitionLabels(s) {
    const n = s.length;
    const last = new Int32Array(26);
    const result = [];
    for (let i = 0; i < n; i++) {
        last[s.charCodeAt(i) - 97] = i;
    }
    let start = 0;
    let end = 0;
    for (let i = 0; i < n; i++) {
        let latest = last[s.charCodeAt(i) - 97];
        if (latest > end) {
            end = latest;
        }
        if (i === end) {
            result.push(end - start + 1);
            start = i + 1;
        }
    }
    return result;
}
