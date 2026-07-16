class Solution {

    private boolean[] chk;
    private boolean hasCircle;

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if (numCourses == 1) return true;

        chk = new boolean[1005];
        hasCircle = false;

        List<List<Integer>> e = new ArrayList<>();
        for (int i=0; i<1005; i++) e.add(new ArrayList<>());

        for (int[] p : prerequisites) {
            int u = p[0], v = p[1];
            if (u == v) return false;
            e.get(v).add(u);
        }

        int root = -1;
        for (int i=0; i<e.size(); i++) {
            List<Integer> adj = e.get(i);
            if (adj.size() == 1) {
                root = i;
                break;
            }
        }
        if (root == -1) return true;

        chk[root] = true;
        DFS(e, root);

        return !hasCircle;
    }

    public void DFS(List<List<Integer>> e, int cur) {
        if (hasCircle) return;

        for (int next : e.get(cur)) {
            if (chk[next]) {
                hasCircle = true;
                return;
            }
            chk[next] = true;
            DFS(e, next);
        }
    }
}
