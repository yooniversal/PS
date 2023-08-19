import java.io.*;
import java.util.*;

public class Main {

    static int[] cache = new int[41];
    static int[] cache2 = new int[41];
    
    public static void main(String[] args) throws IOException {
        Arrays.fill(cache, -1);
        Arrays.fill(cache2, -1);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());

            System.out.printf("%d %d\n", f(n), g(n));
        }
    }

    public static int f(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 0;
        }
        if (cache[n] != -1) {
            return cache[n];
        }
        return cache[n] = f(n-1) + f(n-2);
    }

    public static int g(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (cache2[n] != -1) {
            return cache2[n];
        }
        return cache2[n] = g(n-1) + g(n-2);
    }
}
