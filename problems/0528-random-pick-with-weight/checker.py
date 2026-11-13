from math import log, sqrt


def check(input, output, expected):
    ops = input["ops"]
    weights = input["args"][0][0]
    if not isinstance(output, list) or len(output) != len(ops):
        return "expected one result per operation"
    if output[0] is not None:
        return "constructor result must be null"
    size = len(weights)
    counts = [0] * size
    for i, value in enumerate(output[1:], 1):
        if type(value) is not int or not 0 <= value < size:
            return f"pickIndex result {i} must be an index in [0, {size - 1}]"
        counts[value] += 1
    n = len(output) - 1
    if n == 0:
        return None
    # Individual indices plus up to 16 contiguous buckets catch local and
    # aggregate bias even when the array is much larger than the sample.
    groups = min(16, size)
    mass = [0] * groups
    observed = [0] * groups
    for i, weight in enumerate(weights):
        group = i * groups // size
        mass[group] += weight
        observed[group] += counts[i]
    total = sum(weights)
    k = size + groups
    # Hoeffding gives P(|X-n*p| > b) <= 2 exp(-2*b*b/n).
    # Union over k fixed buckets bounds false rejection by delta=1e-9
    # per case; bucket overlap does not require independent bucket counts.
    bound = sqrt(n * log(2 * k / 1e-9) / 2)
    for i, (weight, count) in enumerate(zip(weights + mass, counts + observed)):
        target = n * weight / total
        if abs(count - target) > bound:
            return f"bucket {i}: observed {count}, expected {target:.2f} within {bound:.2f}"
    return None
