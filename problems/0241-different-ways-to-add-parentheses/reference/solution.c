#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int64_t* values;
    int count;
} Results;

int* diffWaysToCompute(char* expression, int* returnSize) {
    // At most 11 operands fit in the 20-character input.
    int numbers[11];
    char operators[10];
    int n = 0;
    const char* next = expression;
    while (*next) {
        char* end;
        numbers[n] = (int)strtol(next, &end, 10);
        if (*end) {
            operators[n] = *end;
            next = end + 1;
        } else {
            next = end;
        }
        n++;
    }
    Results dp[11][11];
    int catalan[11] = {1};
    for (int length = 2; length <= n; length++) {
        int i = length - 2;
        catalan[i + 1] = catalan[i] * 2 * (2 * i + 1) / (i + 2);
    }
    for (int length = 1; length <= n; length++) {
        for (int left = 0; left + length <= n; left++) {
            int right = left + length - 1;
            Results* result = &dp[left][right];
            result->count = 0;
            result->values = malloc((size_t)catalan[length - 1] * sizeof(*result->values));
            if (length == 1) {
                result->values[result->count++] = numbers[left];
                continue;
            }
            for (int split = left; split < right; split++) {
                Results a = dp[left][split], b = dp[split + 1][right];
                for (int i = 0; i < a.count; i++) {
                    for (int j = 0; j < b.count; j++) {
                        int64_t lhs = a.values[i], rhs = b.values[j];
                        int64_t value = operators[split] == '+' ? lhs + rhs
                                  : operators[split] == '-' ? lhs - rhs : lhs * rhs;
                        result->values[result->count++] = value;
                    }
                }
            }
        }
    }
    for (int left = 0; left < n; left++)
        for (int right = left; right < n; right++)
            if (left != 0 || right != n - 1) free(dp[left][right].values);
    Results full = dp[0][n - 1];
    int* output = malloc((size_t)full.count * sizeof(*output));
    for (int i = 0; i < full.count; i++) output[i] = (int)full.values[i];
    free(full.values);
    *returnSize = full.count;
    return output;
}
