def repeated(rng, n, width, missing):
    return {"s": "a" * n, "p": "a" * (width - 1) + ("b" if missing else "a")}

def alphabet(rng, n, width):
    letters = "abcdefghijklmnopqrstuvwxyz"
    return {"s": (letters * ((n + 25) // 26))[:n], "p": (letters * ((width + 25) // 26))[:width]}
