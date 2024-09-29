import java.io.*;
import java.util.*;

public class Main {

    private static final long MOD = 1000000009L;
    private static long[] cache = new long[1000005];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        init();

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            System.out.println(f(n));
        }

		br.close();
	}

    public static long f(int cur) {
        if (cur < 0) return 0;
        if (cur == 0) return 1;
        if (cache[cur] != -1) return cache[cur];
        cache[cur] = 0;
        
        cache[cur] = (f(cur - 1) % MOD + f(cur - 2) % MOD + f(cur - 3) % MOD);
        cache[cur] %= MOD;

        return cache[cur];
    }

    public static void init() {
        for (int i=0; i<1000005; i++) cache[i] = -1;
    }
}