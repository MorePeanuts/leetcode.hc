def palindrome(rng, n):
    half = [i % 10 for i in range(n // 2)]
    return {"head": half + ([7] if n % 2 else []) + half[::-1]}

def central_mismatch(rng, n):
    values = palindrome(rng, n)["head"]
    values[n // 2] = (values[n // 2] + 1) % 10
    return {"head": values}
