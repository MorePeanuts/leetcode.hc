# Call sequences for Twitter: the constructor, then at most 3 * 10^4 calls.
# Users are in [1, 500]; tweet ids are distinct, in [0, 10^4] (so at most
# 10001 posts), and in random order, so that posting order is not id order.
# No user follows or unfollows himself.

USERS = 500
IDS = 10**4 + 1


class _Ops:
    def __init__(self, rng, posts):
        self.ops, self.args = ["Twitter"], [[]]
        self.ids = rng.sample(range(IDS), posts)

    def post(self, user):
        self.ops.append("postTweet")
        self.args.append([user, self.ids.pop()])

    def feed(self, user):
        self.ops.append("getNewsFeed")
        self.args.append([user])

    def follow(self, a, b):
        self.ops.append("follow")
        self.args.append([a, b])

    def unfollow(self, a, b):
        self.ops.append("unfollow")
        self.args.append([a, b])

    def calls(self):
        return len(self.ops) - 1

    def case(self):
        return {"ops": self.ops, "args": self.args}


def _other(rng, user, users):
    # A random user in [1, users] other than user.
    v = rng.randint(1, users - 1)
    return v + 1 if v >= user else v


def buried(rng, calls, old, new, feeders, followees):
    # The feed of a reader is buried under newer tweets of strangers: the
    # worst case of scanning one global list of tweets from the newest.
    # Readers are users 1 to feeders; each follows the same followees users
    # after them. The old tweets come first, by readers and followees at
    # random; then new tweets by everyone else; then readers, picked at
    # random, read the news feed until the calls run out.
    authors = feeders + followees
    s = _Ops(rng, old + new)
    for r in range(1, feeders + 1):
        for v in range(feeders + 1, authors + 1):
            s.follow(r, v)
    for _ in range(old):
        s.post(rng.randint(1, authors))
    for _ in range(new):
        s.post(rng.randint(authors + 1, USERS))
    while s.calls() < calls:
        s.feed(rng.randint(1, feeders))
    return s.case()


def fan(rng, calls, posts, followees):
    # User 1 follows users 2 to followees + 1 (at most 499), they post every
    # tweet, then user 1 reads the news feed until the calls run out: each
    # feed is 10 of all the tweets, from followees authors.
    s = _Ops(rng, posts)
    for v in range(2, followees + 2):
        s.follow(1, v)
    for _ in range(posts):
        s.post(rng.randint(2, followees + 1))
    while s.calls() < calls:
        s.feed(1)
    return s.case()


def random_mix(rng, calls, posts, users):
    # Random calls among users 1 to users: posts (until the ids run out),
    # feeds, follows and unfollows (also of users not followed), in the
    # proportions 4:4:1:1.
    s = _Ops(rng, posts)
    while s.calls() < calls:
        r = rng.randint(1, 10)
        if r <= 4 and s.ids:
            s.post(rng.randint(1, users))
        elif r <= 8:
            s.feed(rng.randint(1, users))
        else:
            a = rng.randint(1, users)
            b = _other(rng, a, users)
            if r == 9:
                s.follow(a, b)
            else:
                s.unfollow(a, b)
    return s.case()


def churn(rng, calls, posts, followees):
    # User 1 follows and unfollows users 2 to followees + 1 at random, each
    # posting now and then, with a feed of user 1 after every change.
    s = _Ops(rng, posts)
    for v in range(2, followees + 2):
        for _ in range(posts // followees):
            s.post(v)
    while s.calls() + 2 <= calls:
        v = rng.randint(2, followees + 1)
        if rng.randint(0, 1):
            s.follow(1, v)
        else:
            s.unfollow(1, v)
        if s.ids and rng.randint(0, 3) == 0:
            s.post(rng.randint(1, followees + 1))
        else:
            s.feed(1)
    return s.case()
