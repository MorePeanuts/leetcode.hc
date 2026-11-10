package main

import "container/heap"

type tweet struct{ time, id int }

// Each user's tweets in posting order, with a global counter as time.
// A news feed merges the latest tweets of the user and their followees with
// a heap: one entry per author, the next older tweet of that author
// replacing the one taken.
type Twitter struct {
	time      int
	tweets    map[int][]tweet
	following map[int]map[int]bool
}

func Constructor() Twitter {
	return Twitter{tweets: map[int][]tweet{}, following: map[int]map[int]bool{}}
}

func (t *Twitter) PostTweet(userId int, tweetId int) {
	t.tweets[userId] = append(t.tweets[userId], tweet{t.time, tweetId})
	t.time++
}

// cursor points at the next tweet of an author to merge.
type cursor struct {
	list []tweet
	i    int
}

type latest []cursor

func (h latest) Len() int           { return len(h) }
func (h latest) Less(a, b int) bool { return h[a].list[h[a].i].time > h[b].list[h[b].i].time }
func (h latest) Swap(a, b int)      { h[a], h[b] = h[b], h[a] }
func (h *latest) Push(x any)        { *h = append(*h, x.(cursor)) }
func (h *latest) Pop() any {
	old := *h
	x := old[len(old)-1]
	*h = old[:len(old)-1]
	return x
}

func (t *Twitter) GetNewsFeed(userId int) []int {
	h := latest{}
	add := func(author int) {
		if list := t.tweets[author]; len(list) > 0 {
			h = append(h, cursor{list, len(list) - 1})
		}
	}
	add(userId)
	for followee := range t.following[userId] {
		if followee != userId {
			add(followee)
		}
	}
	heap.Init(&h)
	feed := []int{}
	for h.Len() > 0 && len(feed) < 10 {
		c := &h[0]
		feed = append(feed, c.list[c.i].id)
		if c.i > 0 {
			c.i--
			heap.Fix(&h, 0)
		} else {
			heap.Pop(&h)
		}
	}
	return feed
}

func (t *Twitter) Follow(followerId int, followeeId int) {
	if t.following[followerId] == nil {
		t.following[followerId] = map[int]bool{}
	}
	t.following[followerId][followeeId] = true
}

func (t *Twitter) Unfollow(followerId int, followeeId int) {
	delete(t.following[followerId], followeeId)
}
