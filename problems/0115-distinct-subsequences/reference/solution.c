#include <limits.h>
#include <string.h>

int numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    int ways[1001] = {0}; // |t| <= 1000
    ways[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = n; j > 0; j--) {
            if (s[i] == t[j - 1]) {
                ways[j] = ways[j] > INT_MAX - ways[j - 1] ? INT_MAX : ways[j] + ways[j - 1];
            }
        }
    }
    return ways[n];
}
