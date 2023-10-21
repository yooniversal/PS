import java.io.*;
import java.util.*;

public class Main {

    static int INF = 987654322;
    static int n;
    static int[] cache = new int[100005];
    static int[] a;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        a = new int[n];

        for (int i=0; i<100005; ++i) {
            cache[i] = -INF;
        }

        input = br.readLine().split(" ");
        for (int i=0; i<n; ++i) {
            a[i] = Integer.parseInt(input[i]);
        }

        int ret = -987654321;
        for (int i=0; i<n; ++i) {
            ret = Math.max(ret, f(i));
        }

        System.out.println(ret);
    }

    static int f(int cur) {
        if (cur >= n) return 0;
        if(cache[cur] != -INF) return cache[cur];
        cache[cur] = a[cur];

        cache[cur] = Math.max(cache[cur], cache[cur] + f(cur+1));

        return cache[cur];
    }
}
