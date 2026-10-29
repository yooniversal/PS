class Twitter {

    Map<Integer, Tweet> tweetMap;
    Map<Integer, Set<Integer>> followMap;
    int timestamp;

    class Tweet {
        int id;
        int timestamp;
        Tweet next;

        public Tweet(int id, int timestamp) {
            this.id = id;
            this.timestamp = timestamp;
        }
    }

    public Twitter() {
        tweetMap = new HashMap<>();
        followMap = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        Tweet newTweet = new Tweet(tweetId, timestamp++);
        Tweet userTweet = tweetMap.get(userId);

        if (userTweet != null) {
            newTweet.next = userTweet;
        }
        
        tweetMap.put(userId, newTweet);
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new ArrayList<>();

        PriorityQueue<Tweet> pq = new PriorityQueue<>((a, b) -> b.timestamp - a.timestamp);

        // O(FlogF)
        Tweet ownTweet = tweetMap.get(userId);
        if (ownTweet != null) pq.add(ownTweet);

        Set<Integer> follows = followMap.get(userId);
        if (follows != null) {
            for (int follow : follows) {
                Tweet tweet = tweetMap.get(follow);
                if (tweet != null) pq.add(tweet);
            }
        }

        // O(10 * logF) = O(logF)
        while (!pq.isEmpty() && result.size() < 10) {
            Tweet tweet = pq.poll();

            if (tweet.next != null) {
                pq.add(tweet.next);
            }

            result.add(tweet.id);
        }

        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        Set<Integer> follows = followMap.getOrDefault(followerId, new HashSet<>());
        follows.add(followeeId);
        followMap.put(followerId, follows);
    }
    
    public void unfollow(int followerId, int followeeId) {
        Set<Integer> follows = followMap.getOrDefault(followerId, new HashSet<>());
        follows.remove(followeeId);
        followMap.put(followerId, follows);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
