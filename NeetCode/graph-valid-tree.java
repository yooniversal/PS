class Solution {

    private List<List<Integer>> e;
    private boolean[] chk;
    private int cnt;

    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n-1) return false;
        
        e = new ArrayList<>();
        for (int i=0; i<n; i++) e.add(new ArrayList<>());

        chk = new boolean[n];
        cnt = 0;

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            e.get(u).add(v);
            e.get(v).add(u);
        }

        cnt++;
        chk[0] = true;
        DFS(-1, 0);

        return cnt == n;
    }

    public void DFS(int prev, int cur) {
        for (int next : e.get(cur)) {
            if (chk[next]) continue;
            chk[next] = true;
            cnt++;
            DFS(cur, next);
        }
    }
}
