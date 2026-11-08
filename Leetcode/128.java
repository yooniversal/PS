class Solution {

    private Set<Integer> numSet;

    public int longestConsecutive(int[] nums) {
        numSet = new HashSet<>();
        Map<Integer, Integer> cache = new HashMap<>();

        for (int n : nums) {
            numSet.add(n);
        }

        int ret = 0;
        for (int n : nums) {
            if (cache.containsKey(n)) continue;

            int cnt = init(cache, n);

            cache.put(n, cnt);
            ret = Math.max(ret, cnt);
        }

        return ret;
    }

    private int init(Map<Integer, Integer> cache, int cur) {
        if (cache.containsKey(cur)) return cache.get(cur);
        if (!numSet.contains(cur)) return 0;

        int cnt = init(cache, cur+1) + 1;
        cache.put(cur, cnt);
        return cnt;
    }
}
