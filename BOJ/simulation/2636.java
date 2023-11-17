import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static int[][] a;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int stage;
    static int fullCnt, remCnt;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        a = new int[n+1][m+1];
        
        for (int i=0; i<n; i++) {
            String[] inp = br.readLine().split(" ");
            for (int j=0; j<inp.length; j++) {
                a[i][j] = Integer.parseInt(inp[j]);
                fullCnt += a[i][j];
            }
        }

        while (fullCnt > 0) {
            boolean[][] chk = new boolean[n+1][m+1];
            Queue<S> q = new LinkedList<>();
            q.add(new S(0, 0));
            chk[0][0] = true;
            
            stage++;
            // System.out.printf("stage:%d fullCnt:%d\n", stage, fullCnt);
            remCnt = 0;
            while (!q.isEmpty()) {
                S cur = q.poll();
                int x = cur.x, y = cur.y;

                for (int d=0; d<4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (OOB(nx, ny)) continue;
                    if (chk[nx][ny]) continue;
                    chk[nx][ny] = true;

                    if (a[nx][ny] == 0) {
                        q.add(new S(nx, ny));
                    } else {
                        a[nx][ny] = 0;
                        remCnt++;
                        fullCnt--;
                    }
                }
            }
        }

        System.out.println(stage + "\n" + remCnt);
    }

    static boolean OOB(int x, int y) {
        return x<0 || x>=n || y<0 || y>=m;
    }

    static class S {
        int x, y;

        public S(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
