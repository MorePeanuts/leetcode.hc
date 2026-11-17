function wordPattern(pattern, s) {
    const words = s.split(" ");
    if (words.length !== pattern.length) {
        return false;
    }
    const forward = new Map();
    const reverse = new Map();
    for (let i = 0; i < words.length; i++) {
        const letter = pattern[i];
        const word = words[i];
        if ((forward.has(letter) && forward.get(letter) !== word) ||
            (reverse.has(word) && reverse.get(word) !== letter)) {
            return false;
        }
        forward.set(letter, word);
        reverse.set(word, letter);
    }
    return true;
}
