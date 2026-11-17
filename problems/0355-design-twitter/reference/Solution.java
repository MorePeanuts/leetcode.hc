import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

class Twitter {
    private record Tweet(int id, int time, Tweet previous) {}
    private final Map<Integer, Tweet> tweets = new HashMap<>();
    private final Map<Integer, Set<Integer>> following = new HashMap<>();
    private int time = 0;

    public void postTweet(int userId, int tweetId) {
        tweets.put(userId, new Tweet(tweetId, time++, tweets.get(userId)));
    }

    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Tweet> heap = new PriorityQueue<>(Comparator.comparingInt(Tweet::time).reversed());
        Tweet own = tweets.get(userId);
        if (own != null) heap.add(own);
        for (int user : following.getOrDefault(userId, Set.of())) {
            Tweet tweet = tweets.get(user);
            if (tweet != null) heap.add(tweet);
        }
        List<Integer> feed = new ArrayList<>();
        while (!heap.isEmpty() && feed.size() < 10) {
            Tweet newest = heap.remove();
            feed.add(newest.id());
            if (newest.previous() != null) heap.add(newest.previous());
        }
        return feed;
    }

    public void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following.computeIfAbsent(followerId, key -> new HashSet<>()).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        Set<Integer> followees = following.get(followerId);
        if (followees != null) followees.remove(followeeId);
    }
}
