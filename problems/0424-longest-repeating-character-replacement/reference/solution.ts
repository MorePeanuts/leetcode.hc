function characterReplacement(s: string, k: number): number {
    const count = new Int32Array(26);
    let most = 0;
    let left = 0;
    let n = s.length;
    for (let right = 0; right < n; ++right) {
        let frequency = ++count[s.charCodeAt(right) - 65];
        if (frequency > most) {
            most = frequency;
        }
        if (right - left + 1 - most > k) {
            --count[s.charCodeAt(left) - 65];
            ++left;
        }
    }
    return n - left;
}
