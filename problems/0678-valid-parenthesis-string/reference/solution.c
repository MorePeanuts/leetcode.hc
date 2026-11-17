bool checkValidString(char* s) {
    int minimum = 0;
    int maximum = 0;
    for (int i = 0; s[i]; ++i) {
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
