class Solution {
    private int[] uni;

    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        
        uni = new int[n];
        for (int i=0; i<n; i++) uni[i] = i;

        List<int[]> edges = new ArrayList<>();
        for (int i=0; i<n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j=i+1; j<n; j++) {
                int dist = Math.abs(x1 - points[j][0]) + Math.abs(y1 - points[j][1]);
                edges.add(new int[]{dist, i, j});
            }
        }
        edges.sort((a, b) -> Integer.compare(a[0], b[0]));

        int totalCost = 0;
        int edgesCount = 0;

        for (int[] edge : edges) {
            int dist = edge[0], u = edge[1], v = edge[2];

            if (find(u) != find(v)) {
                makeUnion(u, v);
                totalCost += dist;
                edgesCount++;
                if (edgesCount == n-1) {
                    break;
                }
            }
        }

        return totalCost;
    }

    private int find(int x) {
        if (uni[x] == x) return x;
        return uni[x] = find(uni[x]);
    }

    private void makeUnion(int x, int y) {
        int px = find(x), py = find(y);

        if (px < py) {
            uni[py] = px;
        } else {
            uni[px] = py;
        }
    }
}
