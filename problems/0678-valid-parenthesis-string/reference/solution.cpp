class Solution {
public:
    bool checkValidString(std::string s) {
        int minimum = 0;
        int maximum = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            minimum += s[i] == '(' ? 1 : -1;
            maximum += s[i] == ')' ? -1 : 1;
            if (maximum < 0) {
                return false;
            }
            if (minimum < 0) {
                minimum = 0;
            }
        }
        return minimum == 0;
    }
};
