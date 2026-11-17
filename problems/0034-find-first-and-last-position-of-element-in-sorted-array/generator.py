def duplicate_run(rng, n, offset):
    return {"nums": [offset] * n, "target": offset}

def absent(rng, n, offset):
    return {"nums": list(range(offset, offset + n)), "target": offset + n}
