function groupAnagrams(strs: string[]): string[][] {
    const groups = new Map<string, string[]>();
    for (const word of strs) {
        const key = word.split("").sort().join("");
        const group = groups.get(key);
        if (group === undefined) groups.set(key, [word]);
        else group.push(word);
    }
    return Array.from(groups.values());
}
