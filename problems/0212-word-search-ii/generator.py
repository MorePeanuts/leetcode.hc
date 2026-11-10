# Inputs for findWords: a board of 1 to 12 rows and columns of lowercase
# letters, and 1 to 3 * 10^4 distinct words of 1 to 10 lowercase letters.

LETTERS = "abcdefghijklmnopqrstuvwxyz"


def _walk(rng, board, length):
    # The letters of a random path on the board that never revisits a cell,
    # of at most `length` cells: it stops early when it is stuck.
    m, n = len(board), len(board[0])
    i, j = rng.randint(0, m - 1), rng.randint(0, n - 1)
    seen = {(i, j)}
    out = [board[i][j]]
    while len(out) < length:
        nxt = [(a, b) for a, b in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1))
               if 0 <= a < m and 0 <= b < n and (a, b) not in seen]
        if not nxt:
            break
        i, j = rng.choice(nxt)
        seen.add((i, j))
        out.append(board[i][j])
    return "".join(out)


def random_board(rng, m, n, letters, count, maxlen):
    # A random board over the first `letters` letters. Half the candidate
    # words are paths on the board, the others random strings over the same
    # letters, many of them sharing a start with a path; duplicates are
    # dropped, so there are at most `count` words.
    alphabet = LETTERS[:letters]
    board = [[rng.choice(alphabet) for _ in range(n)] for _ in range(m)]
    words = []
    for t in range(count):
        length = rng.randint(1, maxlen)
        if t % 2 == 0:
            words.append(_walk(rng, board, length))
        else:
            words.append("".join(rng.choice(alphabet) for _ in range(length)))
    words = list(dict.fromkeys(words))
    rng.shuffle(words)
    return {"board": board, "words": words}


def _isolated_board(rng, base):
    # A 12 x 12 board of `base`, with each of the 25 other letters once, on
    # cells whose row and column are both even: no two of them are adjacent,
    # and all of them are on the same color of the board's checkerboard.
    others = [c for c in LETTERS if c != base]
    spots = [(i, j) for i in range(0, 12, 2) for j in range(0, 12, 2)]
    board = [[base] * 12 for _ in range(12)]
    for c, (i, j) in zip(others, rng.sample(spots, 25)):
        board[i][j] = c
    return board, others


def deep_tail(rng, base, k):
    # Words of k base letters followed by two other letters: never on the
    # board, since no two other letters are adjacent, but a search for one
    # of them follows every path of k base letters before it fails. With
    # them, the words of 1 to 10 base letters and of 1 to 9 base letters
    # followed by one other letter, which are on the board.
    board, others = _isolated_board(rng, base)
    words = [base * k + x + y for x in others for y in others]
    words += [base * j for j in range(1, 11)]
    words += [base * j + x for j in range(1, 10) for x in others]
    rng.shuffle(words)
    return {"board": board, "words": words}


def deep_middle(rng, base):
    # Words of another letter, 8 base letters and another letter: never on
    # the board, since a path of 9 steps between two cells of the same color
    # does not exist, but a search for one of them follows every path of
    # base letters from the first letter. Words with 7 base letters in the
    # middle, which may be on the board, are added too.
    board, others = _isolated_board(rng, base)
    words = [x + base * 8 + y for x in others for y in others if x != y]
    words += [x + base * 7 + y for x in others for y in others if x != y]
    rng.shuffle(words)
    return {"board": board, "words": words}
