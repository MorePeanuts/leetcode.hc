type Tweet = { id: number; time: number; previous?: Tweet };

class Twitter {
        time = 0;
        tweets = new Map<number, Tweet>();
        following = new Map<number, Set<number>>();

        postTweet(userId: number, tweetId: number): void {
            const previous = this.tweets.get(userId);
            this.tweets.set(userId, { id: tweetId, time: this.time++, previous });
        }

        getNewsFeed(userId: number): number[] {
            const heap: Tweet[] = [];
            const own = this.tweets.get(userId);
            if (own !== undefined) heap.push(own);
            for (const user of this.following.get(userId) ?? []) {
                const tweet = this.tweets.get(user);
                if (tweet !== undefined) heap.push(tweet);
            }

            function siftDown(i: number) {
                const root = heap[i];
                for (let child = 2 * i + 1; child < heap.length; child = 2 * i + 1) {
                    if (child + 1 < heap.length && heap[child + 1].time > heap[child].time) child++;
                    if (root.time >= heap[child].time) break;
                    heap[i] = heap[child];
                    i = child;
                }
                heap[i] = root;
            }

            for (let i = Math.floor(heap.length / 2) - 1; i >= 0; i--) siftDown(i);
            const feed: number[] = [];
            while (heap.length > 0 && feed.length < 10) {
                const root = heap[0];
                feed.push(root.id);
                if (root.previous !== undefined) heap[0] = root.previous;
                else if (heap.length === 1) heap.pop();
                else heap[0] = heap.pop()!;
                if (heap.length > 0) siftDown(0);
            }
            return feed;
        }

        follow(followerId: number, followeeId: number): void {
            if (followerId === followeeId) return;
            const followees = this.following.get(followerId);
            if (followees === undefined) this.following.set(followerId, new Set([followeeId]));
            else followees.add(followeeId);
        }

        unfollow(followerId: number, followeeId: number): void {
            this.following.get(followerId)?.delete(followeeId);
        }
    }
