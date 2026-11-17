#include <stdlib.h>
#include <string.h>

char* minWindow(char* s, char* t) {
    int length = strlen(s);
    int missing = strlen(t);
    int need[256] = {0};
    for (int i = 0; i < missing; i++) need[(unsigned char)t[i]]++;
    int left = 0;
    int bestStart = 0;
    int bestLength = length + 1;
    for (int right = 0; right < length; right++) {
        if (need[(unsigned char)s[right]]-- > 0) missing--;
        if (missing == 0) {
            while (need[(unsigned char)s[left]] < 0) {
                need[(unsigned char)s[left]]++;
                left++;
            }
            int windowLength = right - left + 1;
            if (windowLength < bestLength) {
                bestLength = windowLength;
                bestStart = left;
            }
            need[(unsigned char)s[left]]++;
            missing++;
            left++;
        }
    }
    if (bestLength > length) bestLength = 0;
    char* result = malloc(bestLength + 1);
    memcpy(result, s + bestStart, bestLength);
    result[bestLength] = '\0';
    return result;
}
