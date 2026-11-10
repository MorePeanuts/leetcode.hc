# Operation sequences for WordDictionary. n is the number of addWord and
# search calls (at most 10^4); the constructor comes first and is not
# counted. Words have 1 to 25 letters, and a search pattern at most 2 dots.

LETTERS = "abcdefghijklmnopqrstuvwxyz"


def _case(ops, args):
    return {"ops": ["WordDictionary"] + ops, "args": [[]] + args}


def _word(rng, length, letters):
    return "".join(rng.choice(letters) for _ in range(length))


def _dot(rng, word, dots):
    # word with `dots` distinct positions, at most 2, replaced by dots.
    w = list(word)
    for p in rng.sample(range(len(w)), min(dots, len(w))):
        w[p] = "."
    return "".join(w)


def random_ops(rng, n, maxlen, letters):
    # Random calls over the first `letters` letters, a third of them adds.
    # A search is an added word or a random string of the same length, with
    # 0 to 2 dots, so that both answers are frequent.
    alphabet = LETTERS[:letters]
    ops, args, words = [], [], []
    for _ in range(n):
        if not words or rng.randint(0, 2) == 0:
            w = _word(rng, rng.randint(1, maxlen), alphabet)
            words.append(w)
            ops.append("addWord")
            args.append([w])
            continue
        w = rng.choice(words)
        if rng.randint(0, 1):
            w = _word(rng, len(w), alphabet)
        ops.append("search")
        args.append([_dot(rng, w, rng.randint(0, 2))])
    return _case(ops, args)


def scan_worst(rng, n, shared):
    # n / 2 added words of 25 letters, which share their first `shared`
    # letters and have random tails over "a" to "m", then n / 2 searches with
    # 0 to 2 dots anywhere. A quarter of the searches is an added word, the
    # others share the start too but have a letter from "n" to "z" in their
    # tail, and match nothing: a solution that compares the pattern with
    # every word of its length compares it with all of them, each over at
    # least `shared` letters.
    start = _word(rng, shared, LETTERS)
    ops, args, words = [], [], []
    adds = n // 2
    for _ in range(adds):
        w = start + _word(rng, 25 - shared, LETTERS[:13])
        words.append(w)
        ops.append("addWord")
        args.append([w])
    for _ in range(n - adds):
        if rng.randint(0, 3) == 0:
            w = rng.choice(words)
            q = _dot(rng, w, rng.randint(0, 2))
        else:
            tail = list(_word(rng, 25 - shared, LETTERS[:13]))
            bad = rng.randint(0, len(tail) - 1)
            tail[bad] = rng.choice(LETTERS[13:])
            q = list(start + "".join(tail))
            # The dots avoid the letter that keeps the pattern from matching.
            free = [p for p in range(25) if p != shared + bad]
            for p in rng.sample(free, rng.randint(0, 2)):
                q[p] = "."
            q = "".join(q)
        ops.append("search")
        args.append([q])
    return _case(ops, args)


def dense_dots(rng, n, length):
    # n / 2 random words of the given length over the whole alphabet, then
    # n / 2 searches of that length with exactly 2 dots at random places:
    # the trie branches on every child at both dots.
    ops, args, words = [], [], []
    adds = n // 2
    for _ in range(adds):
        w = _word(rng, length, LETTERS)
        words.append(w)
        ops.append("addWord")
        args.append([w])
    for _ in range(n - adds):
        w = rng.choice(words) if rng.randint(0, 1) else _word(rng, length, LETTERS)
        ops.append("search")
        args.append([_dot(rng, w, 2)])
    return _case(ops, args)
