function checkValidString(s) {
    let minimum = 0;
    let maximum = 0;
    for (let i = 0; i < s.length; ++i) {
        minimum += s[i] === "(" ? 1 : -1;
        maximum += s[i] === ")" ? -1 : 1;
        if (maximum < 0) {
            return false;
        }
        if (minimum < 0) {
            minimum = 0;
        }
    }
    return minimum === 0;
}
