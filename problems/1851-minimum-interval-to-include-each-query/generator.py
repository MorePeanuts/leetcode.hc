def sweep(rng, n, mode):
    if mode == "nested":
        intervals = [[i+1,10000000-i] for i in range(n)]
        queries = [i+1 for i in range(n)]
    elif mode == "expire":
        intervals = [[2*i+1,2*i+2] for i in range(n)]
        queries = [2*i+2 for i in range(n)]
    else:
        intervals = [[3*i+1,3*i+1] for i in range(n)]
        queries = [3*(i//2)+1+i%2 for i in range(n)]
    rng.shuffle(intervals)
    rng.shuffle(queries)
    return {"intervals":intervals,"queries":queries}
