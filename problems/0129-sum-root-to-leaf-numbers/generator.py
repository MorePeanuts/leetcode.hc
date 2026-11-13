def large(rng, n, mode="random"):
    # Complete trees of n<=1000 have depth<=10. The first six levels are zero,
    # so every represented number is <=9999 and the total is < 5,000,000.
    root=[]
    for i in range(n):
        depth=(i+1).bit_length()
        value=0 if depth<=6 else 9 if mode=="nines" else rng.randint(0,9)
        root.append(value)
    return {"root":root}
