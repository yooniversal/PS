class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> pq = new PriorityQueue<Point>(
            (p1, p2) -> Double.compare(p1.d, p2.d)
        );

        for (int[] p : points) {
            pq.add(new Point(p[0], p[1], dist(p[0], p[1])));
        }

        int[][] ret = new int[k][2];
        for (int i=0; i<k; i++) {
            Point cur = pq.poll();
            ret[i][0] = cur.x;
            ret[i][1] = cur.y;
        }

        return ret;
    }

    public double dist(int x, int y) {
        return Math.sqrt(x*x + y*y);
    }

    class Point {
        int x, y;
        double d;

        public Point(int x, int y, double d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }
}
