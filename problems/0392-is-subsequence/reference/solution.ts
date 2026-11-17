function isSubsequence(s: string, t: string): boolean {
    let matched = 0;
    for (let i = 0; matched < s.length && i < t.length; ++i) {
        if (s[matched] === t[i]) {
            ++matched;
        }
    }
    return matched === s.length;
}
