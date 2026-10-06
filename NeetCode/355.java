class Twitter {

    Map<Integer, List<Integer>> tweetMap;
    Map<Integer, Set<Integer>> followMap;
    Map<Integer, Integer> tweetTimeMap;
    int timestamp;

    public Twitter() {
        tweetMap = new HashMap<>();
        followMap = new HashMap<>();
        tweetTimeMap = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        List<Integer> tweets = tweetMap.getOrDefault(userId, new ArrayList<>());
        tweets.add(tweetId);
        tweetMap.put(userId, tweets);
        tweetTimeMap.put(tweetId, timestamp++);
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> ret = new ArrayList<>();

        List<Integer> ownTweets = tweetMap.getOrDefault(userId, List.of());
        ret.addAll(ownTweets);

        Set<Integer> followSet = followMap.getOrDefault(userId, Set.of());
        for (int followId : followSet) {
            List<Integer> followTweets = tweetMap.getOrDefault(followId, List.of());
            ret.addAll(followTweets);
        }

        ret.sort((a, b) -> tweetTimeMap.get(b) - tweetTimeMap.get(a));
        
        while (ret.size() > 10) ret.remove(ret.size() - 1);

        return ret;
    }
    
    public void follow(int followerId, int followeeId) {
        Set<Integer> followSet = followMap.getOrDefault(followerId, new HashSet<>());
        followSet.add(followeeId);
        followMap.put(followerId, followSet);
    }
    
    public void unfollow(int followerId, int followeeId) {
        Set<Integer> followSet = followMap.getOrDefault(followerId, new HashSet<>());

        followSet.remove(followeeId);

        followMap.put(followerId, followSet);
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
