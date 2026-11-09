# Operation sequences for Trie. n is the number of insert, search and
# startsWith calls (at most 3 * 10^4); the constructor comes first and is not
# counted. Every word and prefix has 1 to 2000 lowercase letters.

LETTERS = "abcdefghijklmnopqrstuvwxyz"


def _case(ops, args):
    return {"ops": ["Trie"] + ops, "args": [[]] + args}


def _word(rng, length, letters):
    return "".join(rng.choice(letters) for _ in range(length))


def random_ops(rng, n, maxlen, letters):
    # Random calls on short words over the first `letters` letters, so that
    # words share prefixes. A third of the calls insert; a query is an
    # inserted word, a prefix of one, an extension of one, or a random
    # string, so that both answers are frequent.
    alphabet = LETTERS[:letters]
    ops, args, words = [], [], []
    for _ in range(n):
        r = rng.randint(0, 2)
        if r == 0 or not words:
            w = _word(rng, rng.randint(1, maxlen), alphabet)
            words.append(w)
            ops.append("insert")
            args.append([w])
            continue
        kind = rng.randint(0, 3)
        w = rng.choice(words)
        if kind == 0:
            q = w
        elif kind == 1:
            q = w[: rng.randint(1, len(w))]
        elif kind == 2 and len(w) < maxlen:
            q = w + _word(rng, rng.randint(1, maxlen - len(w)), alphabet)
        else:
            q = _word(rng, rng.randint(1, maxlen), alphabet)
        ops.append("search" if r == 1 else "startsWith")
        args.append([q])
    return _case(ops, args)


def scan_worst(rng, n, length):
    # n / 2 inserts of random words of the given length, then n / 2 queries,
    # four fifths of them startsWith. Most queries match nothing, and the
    # others match one of the last words inserted: a solution that scans the
    # inserted words for a prefix scans all of them on every query.
    ops, args, words = [], [], []
    inserts = n // 2
    for _ in range(inserts):
        w = _word(rng, length, LETTERS)
        words.append(w)
        ops.append("insert")
        args.append([w])
    recent = words[-max(1, inserts // 100):]
    for i in range(n - inserts):
        if rng.randint(0, 3) == 0:
            w = rng.choice(recent)
            q = w if i % 5 == 0 else w[: rng.randint(1, length)]
        else:
            # Four random letters or more: among 15000 words, such a prefix
            # seldom matches.
            q = _word(rng, rng.randint(min(4, length), length), LETTERS)
        ops.append("search" if i % 5 == 0 else "startsWith")
        args.append([q])
    return _case(ops, args)


def long_chain(rng, n):
    # One word of 2000 letters, then its prefixes, longest first: each is
    # searched, every other one is inserted and searched again, and each is
    # a prefix for startsWith. search finds a prefix only once it is
    # inserted itself, while startsWith finds every one.
    base = _word(rng, 2000, "ab")
    ops, args = ["insert"], [[base]]
    k = 2000
    while len(ops) < n:
        k = k - 1 if k > 1 else 2000
        q = base[:k]
        calls = ["search"]
        if k % 2 == 0:
            calls += ["insert", "search"]
        calls.append("startsWith")
        for op in calls[: n - len(ops)]:
            ops.append(op)
            args.append([q])
    return _case(ops, args)


def long_words(rng, n):
    # Words of 1900 to 2000 letters over "ab" that share a common start of at
    # least 1900 letters and differ in their tails; queries are inserted
    # words, their prefixes, and inserted words with one letter changed.
    base = _word(rng, 2000, "ab")
    ops, args, words = [], [], []
    for _ in range(n):
        if not words or rng.randint(0, 2) == 0:
            k = rng.randint(1900, 2000)
            w = base[:k] + _word(rng, rng.randint(0, 2000 - k), "ab")
            words.append(w)
            ops.append("insert")
            args.append([w])
            continue
        w = rng.choice(words)
        kind = rng.randint(0, 2)
        if kind == 0:
            q = w
        elif kind == 1:
            q = w[: rng.randint(1800, len(w))]
        else:
            p = rng.randint(1800, len(w) - 1)
            q = w[:p] + ("b" if w[p] == "a" else "a") + w[p + 1:]
        ops.append("search" if rng.randint(0, 1) else "startsWith")
        args.append([q])
    return _case(ops, args)
