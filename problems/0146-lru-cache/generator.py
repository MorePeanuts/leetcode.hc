# Operation sequences for LRUCache. n is the number of get and put calls
# (at most 2 * 10^5); the constructor comes first and is not counted.


def _case(capacity, ops, args):
    return {"ops": ["LRUCache"] + ops, "args": [[capacity]] + args}


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
            args.append([key, rng.randint(0, 10**5)])
    return _case(capacity, ops, args)


def full_hot(rng, n, capacity):
    # Fills the cache, then only touches keys it holds, chosen at random:
    # every call finds its key, nothing is evicted, and a solution that keeps
    # the keys in a list scans and shifts the whole list on every call.
    ops, args = [], []
    held = rng.sample(range(10**4 + 1), capacity)
    for key in held:
        ops.append("put")
        args.append([key, rng.randint(0, 10**5)])
    for _ in range(n - capacity):
        key = rng.choice(held)
        if rng.randint(0, 1):
            ops.append("get")
            args.append([key])
        else:
            ops.append("put")
            args.append([key, rng.randint(0, 10**5)])
    return _case(capacity, ops, args)


def lru_order(rng, n, capacity):
    # Fills the cache, then gets the least recently used key every time,
    # cycling through the held keys: each get moves the oldest key to the
    # front, the far end of the recency order from where a list keeps it.
    ops, args = [], []
    for key in range(capacity):
        ops.append("put")
        args.append([key, key])
    i = 0
    while len(ops) < n:
        ops.append("get")
        args.append([i % capacity])
        i += 1
    return _case(capacity, ops, args)


def cyclic_evict(rng, n, capacity):
    # Puts capacity + 1 keys in a cycle, so every put after the first
    # capacity evicts, and gets the key that was just evicted (a miss) every
    # third call.
    ops, args = [], []
    i = 0
    while len(ops) < n:
        key = i % (capacity + 1)
        ops.append("put")
        args.append([key, i % (10**5 + 1)])
        i += 1
        if i > capacity and len(ops) < n and i % 3 == 0:
            ops.append("get")
            args.append([(i - capacity - 1) % (capacity + 1)])
    return _case(capacity, ops, args)
