function isPalindrome(s) {
    let left = 0;
    let right = s.length - 1;
    while (left < right) {
        if (!/[a-z0-9]/i.test(s[left])) {
            ++left;
        } else if (!/[a-z0-9]/i.test(s[right])) {
            --right;
        } else {
            if (s[left].toLowerCase() !== s[right].toLowerCase()) {
                return false;
            }
            ++left;
            --right;
        }
    }
    return true;
}
