import java.io.*;
import java.util.*;

public class Main {

    static int m, n, k;
    static int groupSize = 0;
    static boolean[][] chk = new boolean[105][105];
    static boolean[][] a = new boolean[105][105];
    static ArrayList<Integer> groupSizes = new ArrayList<>();
    static int[] dx = new int[]{-1, 1, 0, 0};
    static int[] dy = new int[]{0, 0, 1, -1};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        m = Integer.parseInt(input[0]);
        n = Integer.parseInt(input[1]);
        k = Integer.parseInt(input[2]);

        for (int i=0; i<k; ++i) {
            input = br.readLine().split(" ");
            int x1 = Integer.parseInt(input[0]);
            int y1 = Integer.parseInt(input[1]);
            int x2 = Integer.parseInt(input[2]);
            int y2 = Integer.parseInt(input[3]);

            for (int x=x1; x<x2; ++x) {
                for (int y=y1; y<y2; ++y) {
                    a[x][y] = true;
                }
            }
        }

        int cnt = 0;
        for (int x=0; x<n; ++x) {
            for (int y=0; y<m; ++y) {
                if (a[x][y] || chk[x][y]) continue;
                chk[x][y] = true;
                ++cnt;
                groupSize = 0;
                dfs(x, y);
                groupSizes.add(groupSize);
            }
        }   

        Collections.sort(groupSizes, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return a.compareTo(b);
            }
        });

        System.out.println(cnt);
        for (Integer groupSize : groupSizes) {
            System.out.printf("%d ", groupSize);
        }
        System.out.println();
    }

    static void dfs(int x, int y) {
        ++groupSize;
        
        for (int i=0; i<4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (a[nx][ny] || chk[nx][ny]) continue;
            chk[nx][ny] = true;
            dfs(nx, ny);
        }
    }

    static boolean OOB(int x, int y) {
        return x<0 || x>=n || y<0 || y>=m;
    }
}
