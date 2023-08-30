import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int[][] a;
    static int[][] cache;
    static int INF = 987654321;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        a = new int[n+5][3];
        cache = new int[n+5][3];

        for (int i=0; i<n+5; ++i) {
            for (int j=0; j<3; ++j) {
                cache[i][j] = -1;
            }
        }

        for (int i=0; i<n; ++i) {
            String[] strs = br.readLine().split(" ");
            for (int j=0; j<3; ++j) {
                int v = Integer.parseInt(strs[j]);
                a[i][j] = v;
            }
        }

        int ret = INF;
        for (int i=0; i<3; ++i) {
            ret = Math.min(ret, f(0, i));
        }

        System.out.println(ret);
    }

    static int f(int cur, int before) {
        if (cur >= n) return 0;
        if (cache[cur][before] != -1) return cache[cur][before];
        cache[cur][before] = INF;
        
        for (int i=0; i<3; ++i) {
            if (i == before) continue;
            cache[cur][before] = Math.min(cache[cur][before], f(cur+1, i) + a[cur][i]);
        }

        return cache[cur][before];
    }
}
