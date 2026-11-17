function ladderLength(beginWord: string, endWord: string, wordList: string[]): number {
    if (!wordList.includes(endWord)) return 0;
    const buckets = new Map<string, string[]>();
    function pattern(word: string, i: number) {
        return word.slice(0, i) + "*" + word.slice(i + 1);
    }
    for (const word of wordList) {
        for (let i = 0; i < word.length; i++) {
            const key = pattern(word, i);
            const bucket = buckets.get(key);
            if (bucket === undefined) buckets.set(key, [word]);
            else bucket.push(word);
        }
    }
    const seen = new Set([beginWord]);
    const queue = [beginWord];
    let distance = 1;
    for (let head = 0; head < queue.length; distance++) {
        const end = queue.length;
        for (; head < end; head++) {
            const word = queue[head];
            if (word === endWord) return distance;
            for (let i = 0; i < word.length; i++) {
                const key = pattern(word, i);
                const neighbors = buckets.get(key);
                if (neighbors === undefined) continue;
                buckets.delete(key);
                for (const next of neighbors) {
                    if (!seen.has(next)) {
                        seen.add(next);
                        queue.push(next);
                    }
                }
            }
        }
    }
    return 0;
}
