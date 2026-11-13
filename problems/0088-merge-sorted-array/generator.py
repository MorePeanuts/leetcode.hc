def interleaved(rng, n):
    return {"nums1": [2*i for i in range(n)] + [0]*n, "m": n, "nums2": [2*i+1 for i in range(n)], "n": n}

def right_first(rng, n):
    return {"nums1": list(range(n)) + [0]*n, "m": n, "nums2": list(range(-n, 0)), "n": n}

def one_empty(rng, n):
    return {"nums1": [0]*n, "m": 0, "nums2": list(range(-n, 0)), "n": n}
