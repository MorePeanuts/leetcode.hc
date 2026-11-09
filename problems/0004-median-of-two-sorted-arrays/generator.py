# Two sorted arrays of m and n values in [-10^6, 10^6], with
# 0 <= m, n <= 1000 and 1 <= m + n.


def _sorted(rng, k, lo, hi):
    return sorted(rng.randint(lo, hi) for _ in range(k))


def random_values(rng, m, n, lo, hi):
    # Each array is k random values of [lo, hi], sorted; duplicates likely
    # when the range is narrow.
    return {"nums1": _sorted(rng, m, lo, hi), "nums2": _sorted(rng, n, lo, hi)}


def disjoint(rng, m, n):
    # Every value of nums1 is below every value of nums2: the median lies
    # in one array, or straddles the gap between them.
    return {
        "nums1": _sorted(rng, m, -10**6, -1),
        "nums2": _sorted(rng, n, 0, 10**6),
    }


def interleaved(rng, m, n):
    # m + n distinct values dealt in turn to nums1 and nums2 while both take
    # values, the rest to the longer one.
    values = sorted(rng.sample(range(-10**6, 10**6 + 1), m + n))
    nums1, nums2 = [], []
    for v in values:
        if len(nums2) == n or (len(nums1) < m and len(nums1) <= len(nums2)):
            nums1.append(v)
        else:
            nums2.append(v)
    return {"nums1": nums1, "nums2": nums2}


def constant(rng, m, n, v):
    # Every value of both arrays is v.
    return {"nums1": [v] * m, "nums2": [v] * n}
