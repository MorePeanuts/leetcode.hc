#include <stdbool.h>
#include <stdlib.h>

typedef struct Tweet {
    int id;
    int time;
    struct Tweet* previous;
} Tweet;

typedef struct {
    int time;
    Tweet* tweets[501];
    bool following[501][501];
} Twitter;

Twitter* twitterCreate(void) {
    return calloc(1, sizeof(Twitter));
}

void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    Tweet* tweet = malloc(sizeof(*tweet));
    *tweet = (Tweet){tweetId, obj->time++, obj->tweets[userId]};
    obj->tweets[userId] = tweet;
}

static void siftDown(Tweet** heap, int size, int i) {
    Tweet* tweet = heap[i];
    for (int child = 2 * i + 1; child < size; child = 2 * i + 1) {
        if (child + 1 < size && heap[child + 1]->time > heap[child]->time) child++;
        if (tweet->time >= heap[child]->time) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = tweet;
}

int* twitterGetNewsFeed(Twitter* obj, int userId, int* returnSize) {
    Tweet* heap[500];
    int size = 0;
    for (int user = 1; user <= 500; user++)
        if ((user == userId || obj->following[userId][user]) && obj->tweets[user])
            heap[size++] = obj->tweets[user];
    for (int i = size / 2 - 1; i >= 0; i--) siftDown(heap, size, i);
    int* result = malloc(10 * sizeof(*result));
    *returnSize = 0;
    while (size > 0 && *returnSize < 10) {
        Tweet* root = heap[0];
        result[(*returnSize)++] = root->id;
        if (root->previous) heap[0] = root->previous;
        else heap[0] = heap[--size];
        if (size > 0) siftDown(heap, size, 0);
    }
    return result;
}

void twitterFollow(Twitter* obj, int followerId, int followeeId) {
    obj->following[followerId][followeeId] = true;
}

void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    obj->following[followerId][followeeId] = false;
}

void twitterFree(Twitter* obj) {
    for (int user = 1; user <= 500; user++) {
        Tweet* tweet = obj->tweets[user];
        while (tweet) {
            Tweet* previous = tweet->previous;
            free(tweet);
            tweet = previous;
        }
    }
    free(obj);
}
