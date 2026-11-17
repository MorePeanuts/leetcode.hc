function reverseBits(n) {
    let value = n;
    let answer = 0;
    for (let i = 0; i < 32; i++) {
        answer = (answer << 1) | (value & 1);
        value >>>= 1;
    }
    return answer;
}
