def unit_chain(rng, n, backward):
    arr = [1] * n
    arr[0 if backward else n - 1] = 0
    return {"arr": arr, "start": n - 1 if backward else 0}


def parity_trap(rng, n):
    arr = [2] * n
    arr[1] = 0
    return {"arr": arr, "start": 0}
