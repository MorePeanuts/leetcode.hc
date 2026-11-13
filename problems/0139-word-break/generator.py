def ambiguous(rng, n, valid=False):
    return {"s": "a"*(n-1) + ("a" if valid else "b"), "wordDict": ["a"*i for i in range(1,21)]}
def full_dictionary(rng, n):
    words = ["a"]
    for i in range(999):
        words.append("c" + chr(97+i//676) + chr(97+(i//26)%26) + chr(97+i%26))
    rng.shuffle(words)
    return {"s": "a"*(n-1)+"b", "wordDict":words}
