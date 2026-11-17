function longestPalindrome(s: string): string {
    let n = s.length;
    let start = 0;
    let length = 1;
    for (let center = 0; center < 2 * n - 1; ++center) {
        let left = center >> 1;
        let right = (center + 1) >> 1;
        while (left >= 0 && right < n && s[left] === s[right]) {
            --left;
            ++right;
        }
        if (right - left - 1 > length) {
            start = left + 1;
            length = right - left - 1;
        }
    }
    return s.slice(start, start + length);
}
