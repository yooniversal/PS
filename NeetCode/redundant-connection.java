class Solution {

    private int n;
    private List<List<Integer>> e;

    public int[] findRedundantConnection(int[][] edges) {
        n = edges.length;
        e = new ArrayList<>();
        for (int i=0; i<=n; i++) e.add(new ArrayList<>());
        
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            e.get(u).add(v);
            e.get(v).add(u);
        }

        int[] ret = edges[0];
        for (int i=n-1; i>=0; i--) {
            if (isTree(edges[i])) {
                ret = edges[i];
                break;
            }
        }

        return ret;
    }

    public boolean isTree(int[] cutEdge) {
        boolean[] chk = new boolean[n+5];

        int root = 0;
        for (int i=1; i<=n; i++) {
            int size = e.get(i).size();
            if (cutEdge[0] == i && e.get(i).contains(cutEdge[1])) size--;
            else if (cutEdge[1] == i && e.get(i).contains(cutEdge[0])) size--;

            if (size == 1) {
                root = i;
                break;
            }
        }

        if (root == 0) return false;

        chk[root] = true;

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(-1, root));
        
        int cnt = 0;
        while (!q.isEmpty()) {
            cnt++;
            Pair pair = q.poll();
            int prev = pair.x;
            int cur = pair.y;

            if (cnt == n) return true;

            for (int next : e.get(cur)) {
                if (prev == next) continue;
                if (cutEdge[0] == cur && cutEdge[1] == next) continue;
                if (cutEdge[1] == cur && cutEdge[0] == next) continue;
                if (chk[next]) return false;
                chk[next] = true;
                q.add(new Pair(cur, next));
            }
        }

        return true;
    }

    class Pair {
        int x, y;
    
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
