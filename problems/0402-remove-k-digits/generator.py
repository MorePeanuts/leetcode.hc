def equal_digits(rng, n, digit, k):
    return {"num": digit * n, "k": k}

def plateaus(rng, n, k):
    return {"num": "1" * (n // 3) + "5" * (n // 3) + "9" * (n - 2 * (n // 3)), "k": k}

def leading_zero_result(rng, n):
    return {"num": "9" + "0" * (n - 1), "k": 1}
