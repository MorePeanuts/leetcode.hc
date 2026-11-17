function partition(s) {
    const n = s.length;
    const palindrome = Array.from({ length: n }, () => new Uint8Array(n));
    for (let left = n - 1; left >= 0; left--) {
        for (let right = left; right < n; right++) {
            palindrome[left][right] = s[left] === s[right] &&
                (right - left < 2 || palindrome[left + 1][right - 1]) ? 1 : 0;
        }
    }
    const answer = [];
    const path = [];
    function visit(start) {
        if (start === n) {
            answer.push(path.slice());
            return;
        }
        for (let end = start; end < n; end++) {
            if (palindrome[start][end]) {
                path.push(s.slice(start, end + 1));
                visit(end + 1);
                path.pop();
            }
        }
    }
    visit(0);
    return answer;
}
