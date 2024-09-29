import java.io.*;
import java.util.*;

public class Main {

    private static final long MOD = 1000000009L;
    private static long[][] cache = new long[10005][5];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        init();

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int sum = 0;
            for (int i=1; i<=3; i++) {
                long a = f(n,i);
                // System.out.printf("f(%d, %d)=%d\n",n,i,a);
                sum += a;
            }
            System.out.println(sum);
        }

		br.close();
	}

    public static long f(int cur, int v) {
        if (cur < 0) return 0;
        if (cur == v || v == 1) return 1;
        if (cur < v) return 0;
        if (cache[cur][v] != -1) return cache[cur][v];
        cache[cur][v] = 0;
        // System.out.printf("start -- cur:%d v:%d\n",cur,v);
        
        for (int i=1; i<=v; i++) {
            // System.out.printf("** f(%d, %d)=%d\n",cur-v,i,f(cur-v,i));    
            cache[cur][v] += f(cur - v, i);
        }

        return cache[cur][v];
    }

    public static void init() {
        for (int i=0; i<10005; i++) {
            for (int j=0; j<5; j++) {
                cache[i][j] = -1;
            }
        }
    }
}