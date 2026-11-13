def spaced(rng, n, mode):
    intervals = [[4*i, 4*i+1] for i in range(n)]
    if mode == "cover":
        new = [0, 100000]
    elif mode == "middle":
        new = [4*(n//3)+1, 4*(2*n//3)]
    elif mode == "before":
        intervals = [[a+4,b+4] for a,b in intervals]
        new = [0,1]
    else:
        new = [99999,100000]
    return {"intervals":intervals,"newInterval":new}
