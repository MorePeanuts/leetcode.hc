# Operation sequences for TimeMap. n is the number of set and get calls (at
# most 2 * 10^5); the constructor comes first and is not counted. Keys and
# values are 1 to 100 lowercase letters and digits, timestamps are in
# [1, 10^7], and the timestamps of set strictly increase across all keys:
# each set adds a step of 1 to (10^7 - 1) // n, so even n sets stay within
# 10^7.

ALPHABET = "abcdefghijklmnopqrstuvwxyz0123456789"


def _word(rng, lo, hi):
    return "".join(rng.choice(ALPHABET) for _ in range(rng.randint(lo, hi)))


def _case(ops, args):
    return {"ops": ["TimeMap"] + ops, "args": [[]] + args}


def one_key(rng, n, sets):
    # sets calls to set on one key, then n - sets gets of it at random
    # timestamps up to the last one set: a solution that scans the key's
    # values for each get, from either end, scans half of them on average.
    key = _word(rng, 1, 10)
    step = (10**7 - 1) // n
    ops, args = [], []
    t = 0
    for _ in range(sets):
        t += rng.randint(1, step)
        ops.append("set")
        args.append([key, _word(rng, 1, 8), t])
    for _ in range(n - sets):
        ops.append("get")
        args.append([key, rng.randint(1, t)])
    return _case(ops, args)


def interleaved(rng, n, keys, length):
    # n random calls, half set and half get, on a pool of keys of 1 to length
    # characters (values too). A get asks a key of the pool, or one more key
    # that is never set, at a random timestamp up to a little past the
    # latest set, so some gets come before the key's first set.
    pool = [_word(rng, 1, length) for _ in range(keys)]
    never = "x" * 100
    step = (10**7 - 1) // n
    ops, args = [], []
    t = 0
    for _ in range(n):
        if rng.randint(0, 1):
            t += rng.randint(1, step)
            ops.append("set")
            args.append([rng.choice(pool), _word(rng, 1, length), t])
        else:
            key = never if rng.randint(1, 50) == 1 else rng.choice(pool)
            ops.append("get")
            args.append([key, rng.randint(1, min(10**7, t + step))])
    return _case(ops, args)
