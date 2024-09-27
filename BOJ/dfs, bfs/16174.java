import java.io.*;
import java.util.*;

public class Main {

    static int[] dx = {1, 0};
    static int[] dy = {0, 1};
    static int[][] a = new int[70][70];
    static boolean[][] chk = new boolean[70][70];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        for (int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int j = 0;
            while (st.hasMoreTokens()) {
                a[i][j++] = Integer.parseInt(st.nextToken());
            }
        }

        chk[0][0] = true;
        dfs(0, 0, n);
        System.out.println("Hing");

		br.close();
	}

    public static int go(int d, int power) {
        return d * power;
    }

    public static boolean OOB(int x, int y, int n) {
        return x<0 || x>=n || y<0 || y>=n;
    }

    public static void dfs(int x, int y, int n) {
        if (x == n-1 && y == n-1) {
            System.out.println("HaruHaru");
            System.exit(0);
        }
        
        for (int d=0; d<2; d++) {
            int nx = x + go(dx[d], a[x][y]), ny = y + go(dy[d], a[x][y]);
            if (OOB(nx, ny, n)) continue;
            if (chk[nx][ny]) continue;
            chk[nx][ny] = true;
            dfs(nx, ny, n);
        }
    }
}