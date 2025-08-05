import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int m = Integer.parseInt(inputs[1]);
        int cnt = Integer.parseInt(br.readLine());
        
        int l = 1, r = m;
        int ret = 0;
        for (int i=0; i<cnt; i++) {
            int v = Integer.parseInt(br.readLine());
            if (contains(l, r, v)) continue;
            if (r < v) {
                int diff = v - r;
                l += diff;
                r += diff;
                ret += diff;
            } else {
                int diff = l - v;
                l -= diff;
                r -= diff;
                ret += diff;
            }
        }

        System.out.println(ret);
    }

    static boolean contains(int l, int r, int v) {
        return l <= v && v <= r;
    }
}