from collections import Counter
from math import log, sqrt


def check(input, output, expected):
    values = input["args"][0][0]
    if not isinstance(output, list) or len(output) != len(input["ops"]):
        return "expected one result per operation"
    if output[0] is not None:
        return "constructor result must be null"
    multiplicities = Counter(values)
    counts = Counter()
    for i, value in enumerate(output[1:], 1):
        if type(value) is not int or value not in multiplicities:
            return f"getRandom result {i} must be a value of a node in the list"
        counts[value] += 1
    n = len(output) - 1
    if not n:
        return None
    keys = sorted(multiplicities)
    groups = min(16, len(keys))
    mass = [0] * groups
    observed = [0] * groups
    for i, key in enumerate(keys):
        group = i * groups // len(keys)
        mass[group] += multiplicities[key]
        observed[group] += counts[key]
    # Each NODE is equally likely, so a repeated value has probability
    # equal to its multiplicity divided by the list length.
    k = len(keys) + groups
    # Hoeffding plus a union bound over these k fixed (possibly overlapping)
    # buckets bounds a correct sampler's false rejection by 1e-9 per case.
    bound = sqrt(n * log(2 * k / 1e-9) / 2)
    buckets = [(multiplicities[key], counts[key]) for key in keys]
    buckets.extend(zip(mass, observed))
    for i, (weight, count) in enumerate(buckets):
        target = n * weight / len(values)
        if abs(count - target) > bound:
            return f"bucket {i}: observed {count}, expected {target:.2f} within {bound:.2f}"
    return None
