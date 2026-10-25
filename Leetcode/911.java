class TopVotedCandidate {
    private final int[] times;
    private final int[] leaders;

    public TopVotedCandidate(int[] persons, int[] times) {
        this.times = times;
        this.leaders = new int[persons.length];

        Map<Integer, Integer> votes = new HashMap<>();
        int leader = -1;
        int maxVotes = 0;

        for (int i = 0; i < persons.length; i++) {
            int person = persons[i];
            int count = votes.getOrDefault(person, 0) + 1;
            votes.put(person, count);

            // tie
            if (count >= maxVotes) {
                maxVotes = count;
                leader = person;
            }

            leaders[i] = leader;
        }
    }

    public int q(int t) {
        int l = 0, r = times.length - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (times[mid] <= t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return leaders[r];
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
