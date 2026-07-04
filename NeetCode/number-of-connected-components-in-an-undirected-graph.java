class Solution {

    private boolean[] chk;
    private List<List<Integer>> e;

    public int countComponents(int n, int[][] edges) {
        chk = new boolean[n];
        e = new ArrayList<>();

        int cnt = 0;

        for (int i=0; i<n; i++) e.add(new ArrayList<>());

        for (int[] edge : edges) {
            e.get(edge[0]).add(edge[1]);
            e.get(edge[1]).add(edge[0]);
        }

        for (int i=0; i<n; i++) {
            if (chk[i]) continue;
            chk[i] = true;
            cnt++;
            DFS(i);
        }

        return cnt;
    }

    public void DFS(int cur) {
        for (int next : e.get(cur)) {
            if (chk[next]) continue;
            chk[next] = true;
            DFS(next);
        }
    }
}
