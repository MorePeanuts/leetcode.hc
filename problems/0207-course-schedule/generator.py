# Course graphs: 1 <= numCourses <= 2000, at most 5000 distinct pairs
# [a, b] (a needs b) with 0 <= a, b < numCourses.

import bisect


def _case(n, pairs):
    return {"numCourses": n, "prerequisites": [list(p) for p in pairs]}


def chain(rng, n, cycle):
    # Course i needs course i + 1, so the courses must be taken from the
    # last one back: a path n - 1 deep. With cycle, the last course needs
    # the first, closing a cycle through every course.
    pairs = [(i, i + 1) for i in range(n - 1)]
    if cycle:
        pairs.append((n - 1, 0))
    return _case(n, pairs)


def random_dag(rng, n, e, back):
    # e distinct pairs that follow a random order of the courses (a needs b
    # only when b comes later in the order), so there is no cycle. They
    # include a path through the whole order; with back, the last pair goes
    # from the end of that path to its start, closing a cycle through every
    # course.
    order = list(range(n))
    rng.shuffle(order)
    pairs = {(order[i], order[i + 1]) for i in range(n - 1)}
    want = e - 1 if back else e
    # Pair number k of the order's n * (n - 1) / 2 pairs (i, j), i < j,
    # row by row: row i starts at starts[i].
    starts = [i * (2 * n - i - 1) // 2 for i in range(n)]
    total = n * (n - 1) // 2
    # Distinct ks give distinct pairs, at most n - 1 of them on the path, so
    # e + n of them always reach e pairs.
    for k in rng.sample(range(total), min(total, e + n)):
        if len(pairs) >= want:
            break
        i = bisect.bisect_right(starts, k) - 1
        j = i + 1 + k - starts[i]
        pairs.add((order[i], order[j]))
    pairs = sorted(pairs)
    rng.shuffle(pairs)
    if back:
        pairs.append((order[n - 1], order[0]))
    return _case(n, pairs)


def _layered(count, width):
    pairs = []
    for l in range(count - 1):
        for a in range(width):
            for b in range(width):
                pairs.append((l * width + a, (l + 1) * width + b))
    return pairs


def layers(rng, layers, width):
    # Layers of width courses, each course needing every course of the next
    # layer: no cycle, but width^(layers - 1) paths from the first layer to
    # the last, which a search that does not remember finished courses
    # walks one by one.
    return _case(layers * width, _layered(layers, width))


def layers_cycle(rng, layers, width):
    # The layers above with one more pair from the last course to the first:
    # a cycle, found only at the far end.
    pairs = _layered(layers, width)
    pairs.append((layers * width - 1, 0))
    return _case(layers * width, pairs)


def star(rng, n, inward):
    # Every course needs course 0 (inward), or course 0 needs every course.
    pairs = [(i, 0) if inward else (0, i) for i in range(1, n)]
    return _case(n, pairs)


def no_prerequisites(rng, n):
    return _case(n, [])
