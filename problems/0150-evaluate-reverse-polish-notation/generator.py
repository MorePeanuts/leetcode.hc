# Valid expressions in reverse polish notation: operands in [-200, 200],
# every intermediate value a 32-bit integer and no division by zero, by
# construction. An expression of m operands has 2m - 1 tokens, so n, the
# number of tokens, is odd, at most 9999.

_LO, _HI = -(2**31), 2**31 - 1


def _trunc_div(a, b):
    q = abs(a) // abs(b)
    return q if (a < 0) == (b < 0) else -q


def _apply(op, a, b):
    if op == "+":
        return a + b
    if op == "-":
        return a - b
    if op == "*":
        return a * b
    return _trunc_div(a, b)


def _pick_op(rng, a, b, weights):
    # An operator whose result fits in 32 bits, chosen by weight among
    # those. One always fits: a / b when b is not 0 (but for -2^31 / -1,
    # where a - b fits), and a + b = a when b is 0.
    ok = []
    for op, w in weights:
        if op == "/" and b == 0:
            continue
        if _LO <= _apply(op, a, b) <= _HI:
            ok.append((op, w))
    total = sum(w for _, w in ok)
    r = rng.random() * total
    for op, w in ok:
        r -= w
        if r < 0:
            return op
    return ok[-1][0]


def _operand(rng, small):
    if small:
        return rng.randint(-200, 200)
    # Mostly large magnitudes, so that products grow.
    v = rng.randint(100, 200)
    return v if rng.randint(0, 1) else -v


_MIX = [("+", 3), ("-", 3), ("*", 3), ("/", 1)]


def _build(rng, n, push, small=True, weights=_MIX):
    # push(rng, depth, operands_left) decides, while both are possible,
    # whether the next token is an operand or an operator.
    m = (n + 1) // 2
    tokens, stack = [], []
    left = m
    while left or len(stack) > 1:
        if left and (len(stack) < 2 or push(rng, len(stack), left)):
            v = _operand(rng, small)
            tokens.append(str(v))
            stack.append(v)
            left -= 1
        else:
            b = stack.pop()
            a = stack.pop()
            op = _pick_op(rng, a, b, weights)
            tokens.append(op)
            stack.append(_apply(op, a, b))
    return {"tokens": tokens}


def random_expr(rng, n):
    # Operands and operators at random: a random expression tree.
    return _build(rng, n, lambda rng, d, left: rng.random() < 0.5)


def operands_first(rng, n):
    # Every operand, then every operator: the stack holds all the operands
    # at once, and the expression nests to the right as deep as it can.
    return _build(rng, n, lambda rng, d, left: True)


def chain(rng, n):
    # a b op c op d op ...: the stack never holds more than two values, and
    # the expression nests to the left.
    return _build(rng, n, lambda rng, d, left: False)


def big_values(rng, n):
    # Large operands and mostly multiplications, so that intermediate values
    # come close to the 32-bit limits.
    weights = [("+", 1), ("-", 1), ("*", 6), ("/", 1)]
    return _build(rng, n, lambda rng, d, left: rng.random() < 0.5, False, weights)


def divisions(rng, n):
    # Mostly divisions of values of both signs, which truncate toward zero.
    weights = [("+", 1), ("-", 1), ("*", 3), ("/", 4)]
    return _build(rng, n, lambda rng, d, left: rng.random() < 0.5, True, weights)
