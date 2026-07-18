class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[]>> e = new ArrayList<>();
        for (int i=0; i<=n; i++) e.add(new ArrayList<>());

        for (int[] edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            e.get(u).add(new int[]{v, w});
        }

        int[] dist = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.add(new int[]{k, 0});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int u = cur[0], t = cur[1];

            if (t > dist[u]) continue;

            for (int[] next : e.get(u)) {
                int v = next[0], nextTime = next[1];

                if (dist[v] > dist[u] + nextTime) {
                    dist[v] = dist[u] + nextTime;
                    pq.add(new int[]{v, dist[v]});
                }
            }
        }

        int ret = 0;
        for (int i=1; i<=n; i++) {
            if (dist[i] == Integer.MAX_VALUE) return -1;
            ret = Math.max(ret, dist[i]);
        }

        return ret;
    }
}
