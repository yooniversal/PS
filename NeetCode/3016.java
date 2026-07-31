class Solution {
    public int minimumPushes(String word) {
        int ret = 0;

        int[] cnt = new int[26];
        for (int i=0; i<word.length(); i++) {
            cnt[(int)(word.charAt(i) - 'a')]++;
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int i=0; i<26; i++) {
            if (cnt[i] == 0) continue;
            pq.add(new int[]{i, cnt[i]});
        }

        int index = 0;
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int c = cur[0], count = cur[1];

            int level = index / 8 + 1;
            index++;

            ret += cur[1] * level;
        }

        return ret;
    }
}
