def operations(rng, k, calls, mode):
    ops = ["MyCircularQueue"]
    args = [[k]]
    for i in range(calls):
        if mode == "rotate":
            op = "enQueue" if i < k else ["deQueue", "enQueue", "Front", "Rear", "isFull"][i % 5]
        elif mode == "drain":
            phase = i % (2 * k + 6)
            op = "enQueue" if phase < k else "deQueue" if phase < 2 * k else ["Front", "Rear", "isEmpty", "isFull", "deQueue", "enQueue"][phase - 2 * k]
        else:
            op = rng.choice(["enQueue", "enQueue", "deQueue", "Front", "Rear", "isEmpty", "isFull"])
        ops.append(op)
        args.append([i % 1001] if op == "enQueue" else [])
    return {"ops": ops, "args": args}
