def single_word(rng, n):
    return {"s": "a" * n}

def many_words(rng, n):
    return {"s": ("a1 B2 " * (n // 6) + "c" * (n % 6))[:n]}

def padding(rng, n):
    return {"s": " " * (n // 2) + "word" + " " * (n - n // 2 - 4)}
