function longestCommonPrefix(strs) {
    const first = strs[0];
    for (let i = 0; i < first.length; i++)
        for (const word of strs)
            if (word[i] !== first[i]) return first.slice(0, i);
    return first;
}
