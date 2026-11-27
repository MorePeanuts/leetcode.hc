def linked_accounts(rng, n):
    accounts = [["Alex", f"x{i}@a.com", f"x{i + 1}@a.com"] for i in range(n)]
    rng.shuffle(accounts)
    return {"accounts": accounts}


def distinct_accounts(rng, n):
    return {"accounts": [
        ["Alex", *[f"x{i}y{j}@a.com" for j in range(9)]] for i in range(n)
    ]}


def shared_inbox(rng, n):
    return {"accounts": [
        ["Alex", "shared@a.com", f"x{i}@a.com", "shared@a.com"] for i in range(n)
    ]}
