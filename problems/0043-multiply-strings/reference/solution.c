char* multiply(char* num1, char* num2) {
    int m = (int)strlen(num1);
    int n = (int)strlen(num2);
    int* digits = calloc((size_t)(m + n), sizeof(*digits));
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int place = i + j + 1;
            int total = digits[place] + ((num1[i]) - ('0')) * ((num2[j]) - ('0'));
            digits[place] = total % 10;
            digits[place - 1] += total / 10;
        }
    }
    int start = 0;
    while (start + 1 < m + n && digits[start] == 0) {
        ++start;
    }
    char* answer = malloc((size_t)(m + n - start) + 1);
    for (int i = start; i < m + n; ++i) {
        answer[i - start] = (char)('0' + digits[i]);
    }
    answer[m + n - start] = 0;
    free(digits);
    return answer;
}
