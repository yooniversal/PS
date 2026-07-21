class Solution {

    private boolean hasCircle;
    private boolean[] chk;
    private List<Integer> ret;

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        hasCircle = false;
        chk = new boolean[1005];
        ret = new ArrayList<>();

        int[] indegree = new int[1005];

        List<List<Integer>> e = new ArrayList<>();
        for (int i=0; i<1005; i++) e.add(new ArrayList<>());

        for (int[] p : prerequisites) {
            int u = p[0], v = p[1];
            e.get(u).add(v);
            indegree[v]++;
        }

        List<Integer> roots = new ArrayList<>();
        for (int i=0; i<e.size(); i++) {
            List<Integer> adj = e.get(i);
            if (!adj.isEmpty() && indegree[i] == 0) {
                roots.add(i);
            }
        }

        if (!roots.isEmpty()) {
            for (int root : roots) {
                chk[root] = true;
                DFS(e, root);
                chk[root] = false;
            }
        }

        if (hasCircle) {
            return new int[]{};
        }

        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0 && e.get(i).isEmpty()) {
                ret.add(i);
            }
        }

        return ret.stream()
            .distinct()
            .mapToInt(Integer::intValue)
            .toArray();
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
            chk[next] = false;
        }

        ret.add(cur);
    }
}
