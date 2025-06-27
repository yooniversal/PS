import java.io.*;
import java.util.*;

public class Main {

    static boolean[][] chk;
    static int[][] a;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static boolean ret;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        a = new int[6][6];
        chk = new boolean[6][6];

        for (int i=0; i<5; i++) {
            String[] v = br.readLine().split(" ");
            for (int j=0; j<5; j++) {
                a[i][j] = Integer.parseInt(v[j]);
            }
        }

        String[] v = br.readLine().split(" ");
        int sx = Integer.parseInt(v[0]);
        int sy = Integer.parseInt(v[1]);

        chk[sx][sy] = true;
        dfs(sx, sy, 0, 0);

        System.out.println(ret ? 1 : 0);
	}

    static boolean OOB(int x, int y) {
        return x<0 || x>=5 || y<0 || y>=5;
    }

    static void dfs(int x, int y, int cnt, int score) {
        if (ret) return;
        if (score >= 2) {
            ret = true;
            return;
        }
        if (cnt >= 3) return;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (ret) break;
            if (OOB(nx, ny) || chk[nx][ny] || a[nx][ny] == -1) continue;
            chk[nx][ny] = true;
            dfs(nx, ny, cnt+1, score + a[nx][ny]);
            chk[nx][ny] = false;
        }
    }
}