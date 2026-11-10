# Operation sequences for LFUCache. n is the number of get and put calls
# (at most 2 * 10^5); the constructor comes first and is not counted.
# Keys are in [0, 10^5], values in [0, 10^9], capacity in [1, 10^4].

MAX_KEY = 10**5
MAX_VALUE = 10**9


def _case(capacity, ops, args):
    return {"ops": ["LFUCache"] + ops, "args": [[capacity]] + args}


def random_ops(rng, n, capacity, keys, gets):
    # Random calls on keys 0..keys-1; gets is the share of get calls, in
    # percent. With keys > capacity, puts of new keys evict.
    ops, args = [], []
    for _ in range(n):
        key = rng.randint(0, keys - 1)
        if rng.randint(1, 100) <= gets:
            ops.append("get")
            args.append([key])
        else:
            ops.append("put")
            args.append([key, rng.randint(0, MAX_VALUE)])
    return _case(capacity, ops, args)


def evict_new(rng, n, capacity):
    # Fills the cache and uses each held key a random number of times, then
    # puts a new key on every call: each put evicts the key put just before
    # it, the only one used once, and a solution that scans the cache for
    # the least frequently used key scans all of it every time.
    ops, args = [], []
    held = rng.sample(range(MAX_KEY + 1), capacity)
    for key in held:
        ops.append("put")
        args.append([key, rng.randint(0, MAX_VALUE)])
    for key in held:
        for _ in range(rng.randint(1, 3)):
            ops.append("get")
            args.append([key])
    held_set = set(held)
    fresh = [k for k in range(MAX_KEY + 1) if k not in held_set]
    i = 0
    while len(ops) < n:
        ops.append("put")
        args.append([fresh[i % len(fresh)], rng.randint(0, MAX_VALUE)])
        i += 1
    return _case(capacity, ops, args)


def cyclic_evict(rng, n, capacity):
    # Puts capacity + 1 keys in a cycle: every put after the first capacity
    # evicts, every key has a counter of 1, so the least recently used one
    # goes, and the next put is of the key just evicted.
    ops, args = [], []
    i = 0
    while len(ops) < n:
        ops.append("put")
        args.append([i % (capacity + 1), rng.randint(0, MAX_VALUE)])
        i += 1
    return _case(capacity, ops, args)


def hot_gets(rng, n, capacity):
    # Fills the cache, then gets keys it holds at random, with a put of a new
    # key every tenth call: the counters keep changing, and a solution that
    # keeps the keys sorted by counter moves one on every call.
    ops, args = [], []
    held = rng.sample(range(MAX_KEY + 1), capacity)
    for key in held:
        ops.append("put")
        args.append([key, rng.randint(0, MAX_VALUE)])
    next_key = 0
    held_set = set(held)
    while len(ops) < n:
        if len(ops) % 10 == 0:
            while next_key in held_set:
                next_key += 1
            ops.append("put")
            args.append([next_key, rng.randint(0, MAX_VALUE)])
            held_set.add(next_key)
            held.append(next_key)
        else:
            ops.append("get")
            args.append([rng.choice(held)])
    return _case(capacity, ops, args)
