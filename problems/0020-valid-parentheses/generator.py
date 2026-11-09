# Strings of the six brackets, at most 10^4 long.

_OPEN = "([{"
_CLOSE = {"(": ")", "[": "]", "{": "}"}


def nested(rng, n):
    # n / 2 openers of random types, then their closers: valid, and the
    # deepest nesting there is. Removing matched pairs one round at a time
    # takes n / 2 rounds.
    opens = [rng.choice(_OPEN) for _ in range(n // 2)]
    return {"s": "".join(opens) + "".join(_CLOSE[c] for c in reversed(opens))}


def nested_wrong_last(rng, n):
    # Like nested, but the last closer is of the wrong type: invalid, and
    # found only at the very end.
    opens = [rng.choice(_OPEN) for _ in range(n // 2)]
    closes = [_CLOSE[c] for c in reversed(opens)]
    closes[-1] = _CLOSE[_OPEN[(_OPEN.index(opens[0]) + 1) % 3]]
    return {"s": "".join(opens) + "".join(closes)}


def random_valid(rng, n, depth):
    # A random valid string of n brackets (n even) whose nesting stays at
    # most depth deep.
    out, stack = [], []
    while len(out) < n:
        left = n - len(out)
        if stack and (len(stack) == left or len(stack) >= depth or rng.random() < 0.5):
            out.append(_CLOSE[stack.pop()])
        else:
            c = rng.choice(_OPEN)
            stack.append(c)
            out.append(c)
    return {"s": "".join(out)}


def all_open(rng, n):
    # Openers only: invalid, every bracket stays on the stack.
    return {"s": "".join(rng.choice(_OPEN) for _ in range(n))}
