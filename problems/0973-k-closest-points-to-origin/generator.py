# Inputs for kClosest: 1 <= k <= n <= 10^4 points with coordinates in
# [-10^4, 10^4]. The answer is unique by construction: when k < n, the k-th
# smallest squared distance is strictly less than the (k+1)-th.

C = 10**4


def _d(p):
    return p[0] * p[0] + p[1] * p[1]


def _unique(points, k):
    # Makes the answer unique: every point at the k-th smallest distance t
    # beyond the first k (in distance order) moves one step away from the
    # origin, to a distance above t. No point is at a corner (+-10^4, +-10^4),
    # so t < 2 * 10^8 and one coordinate can always grow.
    order = sorted(range(len(points)), key=lambda i: _d(points[i]))
    t = _d(points[order[k - 1]])
    for i in order[k:]:
        x, y = points[i]
        if _d(points[i]) != t:
            break
        if abs(x) < C:
            x += 1 if x >= 0 else -1
        else:
            y += 1 if y >= 0 else -1
        points[i] = [x, y]
    return {"points": points, "k": k}


def _point(rng, lo, hi):
    x, y = rng.randint(lo, hi), rng.randint(lo, hi)
    if abs(x) == C and abs(y) == C:
        y -= 1 if y > 0 else -1
    return [x, y]


def random_points(rng, n, k):
    # n random points over the whole range.
    return _unique([_point(rng, -C, C) for _ in range(n)], k)


def small_box(rng, n, k, r):
    # n random points in [-r, r]^2: many points at equal distances, and
    # duplicate points.
    return _unique([_point(rng, -r, r) for _ in range(n)], k)


def descending(rng, n, k):
    # n random points ordered farthest first: every point read is closer
    # than all before it.
    points = [_point(rng, -C, C) for _ in range(n)]
    points.sort(key=_d, reverse=True)
    return _unique(points, k)


def lattice_disk(rng, r):
    # The 9801 lattice points of [-49, 49]^2 in random order; k is the number
    # of them within distance r of the origin (the origin included, so
    # k >= 1): every distance has ties, the answer is still unique.
    points = [[x, y] for x in range(-49, 50) for y in range(-49, 50)]
    rng.shuffle(points)
    k = sum(1 for p in points if _d(p) <= r * r)
    return {"points": points, "k": k}


def duplicates(rng, n, groups, take):
    # groups distinct points at distinct distances from the origin (distinct
    # radii, each on a random half-axis), each repeated about n / groups
    # times; k covers the take closest groups.
    pts = []
    for r in sorted(rng.sample(range(C + 1), groups)):
        pts.append(rng.choice([[r, 0], [-r, 0], [0, r], [0, -r]]))
    points = [list(pts[i % groups]) for i in range(n)]
    k = sum(1 for i in range(n) if i % groups < take)
    rng.shuffle(points)
    return {"points": points, "k": k}
