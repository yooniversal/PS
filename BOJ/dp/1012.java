import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static int[] dx = new int[]{0, 0, 1, -1};
    static int[] dy = new int[]{1, -1, 0, 0};

    static int[][] a = new int[51][51];
    static boolean[][] chk = new boolean[51][51];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            String[] strs = br.readLine().split(" ");
            n = Integer.parseInt(strs[0]);
            m = Integer.parseInt(strs[1]);
            int k = Integer.parseInt(strs[2]);

            for(int i=0; i<51; ++i) for(int j=0; j<51; ++j) {
                a[i][j] = 0;
                chk[i][j] = false;
            }

            for (int i=0; i<k; ++i) {
                String[] xy = br.readLine().split(" ");
                int x = Integer.parseInt(xy[0]);
                int y = Integer.parseInt(xy[1]);
                a[x][y] = 1;
                
            }

            int ret = 0;

            for (int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                    if(a[i][j] == 0 || chk[i][j]) continue;
                    chk[i][j] = true;
                    ++ret;
                    dfs(i, j);
                }
            }

            System.out.println(ret);
        }
    }

    public static void dfs(int x, int y) {
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(OOB(nx, ny)) continue;
            if(a[nx][ny] == 0 || chk[nx][ny]) continue;
            chk[nx][ny] = true;
            dfs(nx, ny);
        }
    }

    public static boolean OOB(int x, int y) {
        return x<0 || x>=n || y<0 || y>=m;
    }
}
