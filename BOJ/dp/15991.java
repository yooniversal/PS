import java.io.*;
import java.util.*;

public class Main {

    private static final long MOD = 1000000009L;
    private static long[] cache = new long[100005];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        init();

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] list = {0, 1, 2, 3};

            long sum = 0;
            for (int i : list) {
                sum += f(n - i) % MOD;
                sum %= MOD;
            }
            System.out.println(sum);
        }

		br.close();
	}

    public static long f(int cur) {
        if (cur < 0 || cur % 2 != 0) return 0;
        if (cur == 0) return 1;
        if (cache[cur] != -1) return cache[cur];
        cache[cur] = 0;

        int[] list = {2, 4, 6};
        
        for (int i : list) {
            cache[cur] += f(cur - i) % MOD;
            cache[cur] %= MOD;
        }

        return cache[cur];
    }

    public static void init() {
        for (int i=0; i<100005; i++) {
            cache[i] = -1;
        }
    }
}