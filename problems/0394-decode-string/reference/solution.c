#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t length;
    int repeat;
} Frame;

char* decodeString(char* s) {
    Frame stack[30];
    int depth = 0;
    int repeat = 0;
    size_t length = 0;
    size_t capacity = 32;
    char* decoded = malloc(capacity);
    for (const char* next = s; *next; next++) {
        char ch = *next;
        if (ch >= '0' && ch <= '9') {
            repeat = repeat * 10 + ch - '0';
        } else if (ch == '[') {
            stack[depth++] = (Frame){length, repeat};
            repeat = 0;
        } else if (ch == ']') {
            Frame frame = stack[--depth];
            size_t width = length - frame.length;
            size_t total = frame.length + width * (size_t)frame.repeat;
            while (total + 1 > capacity) {
                capacity *= 2;
                decoded = realloc(decoded, capacity);
            }
            for (int i = 1; i < frame.repeat; i++) {
                memcpy(decoded + length, decoded + frame.length, width);
                length += width;
            }
        } else {
            if (length + 1 == capacity) {
                capacity *= 2;
                decoded = realloc(decoded, capacity);
            }
            decoded[length++] = ch;
        }
    }
    decoded[length] = '\0';
    return decoded;
}
