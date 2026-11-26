function reverseString(s) {
    for (let left = 0, right = s.length - 1; left < right; left++, right--) {
        const first = s[left];
        s[left] = s[right];
        s[right] = first;
    }
}
