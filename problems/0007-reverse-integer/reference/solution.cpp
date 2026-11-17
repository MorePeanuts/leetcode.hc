class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;
        int remaining = negative ? x : -x;
        int answer = 0;
        int lastDigit = negative ? -8 : -7;
        while (remaining != 0) {
            int digit = remaining % 10;
            if (answer < -214748364 || (answer == -214748364 && digit < lastDigit))
                return 0;
            answer = answer * 10 + digit;
            remaining /= 10;
        }
        return negative ? answer : -answer;
    }
};
