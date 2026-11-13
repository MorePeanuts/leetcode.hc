def arithmetic(rng, n, m, k, offset=-1000000000, step1=3, step2=5):
    return {"nums1": [offset + step1 * i for i in range(n)],
            "nums2": [offset + step2 * i for i in range(m)], "k": k}


def repeated(rng, n, m, k, value1=0, value2=0):
    return {"nums1": [value1] * n, "nums2": [value2] * m, "k": k}


def sorted_random(rng, n, m, k):
    return {"nums1": sorted(rng.randint(-1000000000, 1000000000) for _ in range(n)),
            "nums2": sorted(rng.randint(-1000000000, 1000000000) for _ in range(m)),
            "k": k}
