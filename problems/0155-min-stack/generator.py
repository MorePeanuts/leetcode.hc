# Operation sequences for MinStack. n is the number of push, pop, top and
# getMin calls (at most 3 * 10^4); the constructor comes first and is not
# counted. pop, top and getMin are only called on a non-empty stack.

_LO, _HI = -(2**31), 2**31 - 1


def _case(ops, args):
    return {"ops": ["MinStack"] + ops, "args": [[]] + args}


def push_then_query(rng, n, pushes):
    # pushes random values, then only top and getMin calls on the full
    # stack: a solution that scans the stack for the minimum scans all of
    # it on every getMin.
    ops, args = [], []
    for _ in range(pushes):
        ops.append("push")
        args.append([rng.randint(_LO, _HI)])
    while len(ops) < n:
        if rng.randint(0, 9) == 0:
            ops.append("top")
        else:
            ops.append("getMin")
        args.append([])
    return _case(ops, args)


def descending_then_pop(rng, n, pushes):
    # Pushes distinct values in descending order, then pops them one by one,
    # each pop followed by getMin, as long as the calls allow: every pop
    # removes the minimum, so a solution that recomputes the minimum after
    # popping it rescans the stack, and one that scans on getMin does too.
    k = pushes
    values = sorted(rng.sample(range(_LO, _HI + 1), k), reverse=True)
    ops, args = [], []
    for v in values:
        ops.append("push")
        args.append([v])
    while len(ops) + 2 <= n and k > 1:
        ops.append("pop")
        args.append([])
        ops.append("getMin")
        args.append([])
        k -= 1
    while len(ops) < n:
        ops.append("top")
        args.append([])
    return _case(ops, args)


def churn(rng, n, depth, query):
    # Grows the stack to depth with random non-negative values, then
    # repeatedly pushes a new negative minimum and pops it again, with a
    # getMin in between when query is true: the stack stays deep, and the
    # minimum changes on every push and pop.
    ops, args = [], []
    for _ in range(depth):
        ops.append("push")
        args.append([rng.randint(0, _HI)])
    cycle = 3 if query else 2
    while len(ops) + cycle <= n:
        ops.append("push")
        args.append([rng.randint(_LO, -1)])
        if query:
            ops.append("getMin")
            args.append([])
        ops.append("pop")
        args.append([])
    while len(ops) < n:
        ops.append("getMin")
        args.append([])
    return _case(ops, args)


def random_ops(rng, n, lo, hi):
    # Random calls with values in [lo, hi]; pushes are a little more likely
    # than pops, so the stack grows over the run. A narrow range repeats
    # the minimum.
    ops, args = [], []
    size = 0
    for _ in range(n):
        r = rng.randint(0, 9)
        if size == 0 or r < 4:
            ops.append("push")
            args.append([rng.randint(lo, hi)])
            size += 1
        elif r < 7:
            ops.append("pop")
            args.append([])
            size -= 1
        elif r < 8:
            ops.append("top")
            args.append([])
        else:
            ops.append("getMin")
            args.append([])
    return _case(ops, args)
