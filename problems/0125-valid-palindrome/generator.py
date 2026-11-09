# Inputs of printable ASCII only (" " to "~"), as the constraints say.

_ALNUM = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
_OTHER = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"


def _swapcase(rng, c):
    # A letter in either case, so that only a case-insensitive compare passes.
    return c.upper() if c.isalpha() and rng.random() < 0.5 else c


def _noisy(rng, core, n):
    # The alphanumeric core spread over n characters, the rest punctuation.
    gaps = n - len(core)
    out = []
    per = gaps // (len(core) + 1)
    extra = gaps - per * (len(core) + 1)
    for c in core:
        out.append("".join(rng.choice(_OTHER) for _ in range(per)))
        out.append(_swapcase(rng, c))
    out.append("".join(rng.choice(_OTHER) for _ in range(per + extra)))
    return "".join(out)


def palindrome(rng, n, alnum):
    # A palindrome of `alnum` letters and digits, lowercase, mixed with
    # punctuation and spaces up to n characters.
    half = [rng.choice(_ALNUM[:26] + _ALNUM[52:]) for _ in range(alnum // 2)]
    mid = [rng.choice(_ALNUM[:26])] if alnum % 2 else []
    return {"s": _noisy(rng, half + mid + half[::-1], n)}


def middle_mismatch(rng, n, alnum):
    # Like palindrome, but the two characters next to the middle differ: two
    # pointers compare every other pair before they find it.
    half = [rng.choice("abcdefghij") for _ in range(alnum // 2)]
    other = half[::-1]
    other[0] = "z" if other[0] != "z" else "y"
    return {"s": _noisy(rng, half + other, n)}


def all_other(rng, n):
    # No letter or digit at all: the empty string, a palindrome.
    return {"s": "".join(rng.choice(_OTHER) for _ in range(n))}


def one_letter(rng, n):
    # One letter in both cases, no punctuation.
    return {"s": "".join(rng.choice("aA") for _ in range(n))}
