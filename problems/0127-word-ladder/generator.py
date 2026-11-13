def dictionary(rng, n, width, reachable=False):
    def word(value):
        letters = ["a"] * width
        for i in range(width-1,-1,-1):
            letters[i] = chr(97 + value%26)
            value //= 26
        return "".join(letters)
    words = [word(i) for i in range(n-1)]
    end = words[-1] if reachable else "z" * width
    if reachable:
        words.append(word(n-1))
    else:
        words.append(end)
    rng.shuffle(words)
    return {"beginWord":"a"*width,"endWord":end,"wordList":words}
