def long_scan(rng, n, mode):
    if mode == 0:
        return {"s": "a"*99+"b", "t": "a"*(n-1)+"b"}
    if mode == 1:
        return {"s": "a"*99+"b", "t": "a"*n}
    return {"s": "z"*100, "t": "a"*(n-100)+"z"*100}
