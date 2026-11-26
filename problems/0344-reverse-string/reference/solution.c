void reverseString(char* s, int sSize) {
    for (int left = 0, right = sSize - 1; left < right; left++, right--) {
        char first = s[left];
        s[left] = s[right];
        s[right] = first;
    }
}
