import java.io.*;
import java.util.*;

public class Main {

    static int[] dx = {1, 0};
    static int[] dy = {0, 1};

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] a = new int[n][n];
        boolean[][] chk = new boolean[n][n];

        for (int i=0; i<n; i++) {
            String[] inputs = br.readLine().split(" ");
            for (int j=0; j<n; j++) {
                int v = Integer.parseInt(inputs[j]);
                a[i][j] = v;
            }
        }

        chk[0][0] = true;
        Queue<Status> q = new LinkedList<>();
        q.add(new Status(0, 0));

        while (!q.isEmpty()) {
            Status cur = q.poll();

            if (cur.x == n-1 && cur.y == n-1) {
                System.out.println("HaruHaru");
                return;
            }
            
            for (int i=0; i<2; i++) {
                int nx = cur.x + dx[i] * a[cur.x][cur.y];
                int ny = cur.y + dy[i] * a[cur.x][cur.y];
                if (OOB(nx, ny, n) || chk[nx][ny]) continue;
                chk[nx][ny] = true;
                q.add(new Status(nx, ny));
            }
        }

        System.out.println("Hing");
    }

    static boolean OOB(int x, int y, int n) {
        return x<0 || x>=n || y<0 || y>=n;
    }

    static class Status {
        int x;
        int y;

        public Status(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}