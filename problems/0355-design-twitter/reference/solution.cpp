#include <array>
#include <queue>
#include <unordered_set>
#include <vector>

class Twitter {
    struct Tweet {
        int id;
        int time;
    };
    struct Cursor {
        const std::vector<Tweet>* tweets;
        int index;

        bool operator<(const Cursor& other) const {
            return (*tweets)[index].time < (*other.tweets)[other.index].time;
        }
    };
    std::array<std::vector<Tweet>, 501> tweets;
    std::array<std::unordered_set<int>, 501> following;
    int time = 0;

public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time++});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<Cursor> heap;
        auto insert = [&](int user) {
            if (!tweets[user].empty())
                heap.push({&tweets[user], static_cast<int>(tweets[user].size()) - 1});
        };
        insert(userId);
        for (int user : following[userId]) insert(user);
        std::vector<int> feed;
        while (!heap.empty() && feed.size() < 10) {
            auto cursor = heap.top();
            heap.pop();
            feed.push_back((*cursor.tweets)[cursor.index].id);
            if (--cursor.index >= 0) heap.push(cursor);
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
