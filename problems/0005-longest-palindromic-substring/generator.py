import string

ALPHABET = string.ascii_letters + string.digits


def all_same(rng, n, ch):
    # Every substring is a palindrome: the worst case of expanding around
    # centers, and of checking every substring.
    return {"s": ch * n}


def random_string(rng, n, alphabet):
    return {"s": "".join(rng.choice(alphabet) for _ in range(n))}


def alternating(rng, n):
    # "abab...": every odd-length substring is a palindrome, no even one is.
    return {"s": "".join("ab"[i % 2] for i in range(n))}


def planted(rng, n, length, at):
    # A random palindrome of the given length planted at offset `at` in
    # random text over the full alphabet.
    half = "".join(rng.choice(ALPHABET) for _ in range(length // 2))
    middle = rng.choice(ALPHABET) if length % 2 else ""
    pal = half + middle + half[::-1]
    rest = [rng.choice(ALPHABET) for _ in range(n - length)]
    return {"s": "".join(rest[:at]) + pal + "".join(rest[at:])}


def nearly_same(rng, n, at):
    # All 'a' but one 'b': the longest palindrome is centered on the 'b'
    # or is the longer run of 'a'.
    s = ["a"] * n
    s[at] = "b"
    return {"s": "".join(s)}


def separated_runs(rng, n, m):
    # Runs of one letter, each of about m (within 10%), separated by letters
    # that are all different: a palindrome holds at most one separator, at
    # its center, so the answer is only about 2m + 1 long. The worst case of
    # checking substrings from the longest down: every length above the
    # answer is tried, and each window matches until a separator.
    run = rng.choice(ALPHABET)
    seps = rng.sample([c for c in ALPHABET if c != run], n // (m - m // 10 + 1) + 1)
    parts = []
    size = 0
    while size < n:
        if parts:
            parts.append(seps.pop())
            size += 1
        k = min(rng.randint(m - m // 10, m + m // 10), n - size)
        parts.append(run * k)
        size += k
    return {"s": "".join(parts)[:n]}
