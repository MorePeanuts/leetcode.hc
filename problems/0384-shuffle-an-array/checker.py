from collections import Counter
from itertools import permutations
from math import factorial, log, sqrt


def check(input, output, expected):
    ops = input["ops"]
    original = input["args"][0][0]
    n = len(original)
    if not isinstance(output, list) or len(output) != len(ops):
        return "expected one result per operation"
    if output[0] is not None:
        return "constructor result must be null"
    positions = {value: i for i, value in enumerate(original)}
    counts = [[0] * n for _ in range(n)]
    arrangements = Counter()
    samples = 0
    for call, (op, value) in enumerate(zip(ops[1:], output[1:]), 1):
        if not isinstance(value, list) or len(value) != n:
            return f"result {call} must be an array of length {n}"
        if any(type(x) is not int for x in value) or set(value) != set(original):
            return f"result {call} is not a permutation of the original array"
        if op == "reset":
            if value != original:
                return f"reset result {call} must restore the original order"
        else:
            samples += 1
            for position, element in enumerate(value):
                counts[position][positions[element]] += 1
            if n <= 6:
                arrangements[tuple(value)] += 1
    if not samples:
        return None
    # Test marginal positions plus ALL permutation buckets for n <= 6.
    # Marginals alone would wrongly accept random cyclic rotations.
    k = n * n + (factorial(n) if n <= 6 else 0)
    # For each fixed bucket Hoeffding bounds deviation by
    # 2*exp(-2*b*b/samples). Union over k bounds false rejection
    # by delta=1e-9 per case; overlapping buckets need not be independent.
    bound = sqrt(samples * log(2 * k / 1e-9) / 2)
    for position, row in enumerate(counts):
        for element, count in enumerate(row):
            if abs(count - samples / n) > bound:
                return f"position {position}, value {original[element]} has implausible frequency {count}"
    if n <= 6:
        target = samples / factorial(n)
        for arrangement in permutations(original):
            count = arrangements[arrangement]
            if abs(count - target) > bound:
                return f"permutation {arrangement} has implausible frequency {count}"
    return None
