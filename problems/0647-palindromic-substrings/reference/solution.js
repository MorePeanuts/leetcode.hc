function countSubstrings(s) {
    let count = 0;
    let n = s.length;
    for (let center = 0; center < 2 * n - 1; ++center) {
        let left = center >> 1;
        let right = (center + 1) >> 1;
        while (left >= 0 && right < n && s[left] === s[right]) {
            ++count;
            --left;
            ++right;
        }
    }
    return count;
}
