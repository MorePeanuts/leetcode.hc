function numDecodings(s) {
    let twoBack = 1;
    let oneBack = s[0] === '0' ? 0 : 1;
    let length = s.length;
    for (let i = 1; i < length; i++) {
        let current = s[i] !== '0' ? oneBack : 0;
        if (s[i - 1] === '1' || (s[i - 1] === '2' && s[i] <= '6')) current += twoBack;
        twoBack = oneBack;
        oneBack = current;
    }
    return oneBack;
}
