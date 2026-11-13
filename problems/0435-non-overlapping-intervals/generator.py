def chain(rng, n, mode):
    intervals = [[-50000+i,-49999+i] for i in range(n)]
    if mode == "reverse":
        intervals.reverse()
    elif mode == "shuffle":
        rng.shuffle(intervals)
    return {"intervals":intervals}


def nested(rng, n):
    return {"intervals":[[-50000+i%50000,50000-i%50000] for i in range(n)]}
