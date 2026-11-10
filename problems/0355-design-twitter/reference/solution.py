import heapq
from collections import defaultdict


class Twitter:
    # Each user's tweets in posting order, with a global counter as time.
    # A news feed merges the latest tweets of the user and their followees
    # with a heap: one entry per author, the next older tweet of that author
    # replacing the one taken.
    def __init__(self):
        self.time = 0
        self.tweets: defaultdict[int, list[tuple[int, int]]] = defaultdict(list)
        self.following: defaultdict[int, set[int]] = defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId: int) -> list[int]:
        heap = []
        for author in self.following[userId] | {userId}:
            own = self.tweets.get(author)
            if own:
                i = len(own) - 1
                heap.append((-own[i][0], own[i][1], author, i))
        heapq.heapify(heap)
        feed = []
        while heap and len(feed) < 10:
            _, tweet, author, i = heapq.heappop(heap)
            feed.append(tweet)
            if i > 0:
                t, nxt = self.tweets[author][i - 1]
                heapq.heappush(heap, (-t, nxt, author, i - 1))
        return feed

    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].discard(followeeId)
