class Solution {
    private static int N, M;
    private final int[] dx = {-1, 1, 0, 0};
    private final int[] dy = {0, 0, 1, -1};

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        N = image.length;
        M = image[0].length;

        int startColor = image[sr][sc];
        boolean[][] visited = new boolean[N][M];

        Queue<int[]> q = new LinkedList<>();
        
        q.add(new int[]{sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (OOB(nx, ny)) continue;
                if (visited[nx][ny]) continue;
                if (image[nx][ny] != startColor) continue;

                visited[nx][ny] = true;
                image[nx][ny] = color;
                q.add(new int[]{nx, ny});
            }
        }

        return image;
    }

    private boolean OOB(int x, int y) {
        return x < 0 || x >= N || y < 0 || y >= M;
    }
}
