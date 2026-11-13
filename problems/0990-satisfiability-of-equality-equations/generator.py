def equality_chain(rng, n, conflict):
    equations = [chr(97 + i) + "==" + chr(98 + i) for i in range(25)]
    equations += ["a==z"] * (n - 26)
    equations.append("a!=z" if conflict else "z==a")
    rng.shuffle(equations)
    return {"equations": equations}


def separate_groups(rng, n):
    equations = [chr(97 + i) + "==" + chr(98 + i) for i in range(25) if i != 12]
    equations += ["a!=z"] * (n - len(equations))
    rng.shuffle(equations)
    return {"equations": equations}
