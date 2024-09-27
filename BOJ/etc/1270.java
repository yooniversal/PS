import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        for (int i=0; i<n; i++) {
            String[] input = br.readLine().split(" ");
            long[] a = new long[input.length];
            for (int j=0; j<input.length; j++) {
                a[j] = Long.parseLong(input[j]);
            }

            Map<Long, Long> m = new HashMap<>();
            for (int j=1; j<a.length; j++) {
                Long b = m.get(a[j]) == null ? 0L : m.get(a[j]);

                m.put(a[j], b + 1);
            }

            boolean flag = true;
            Map<Long, Boolean> chk = new HashMap<>();
            for (int j=1; j<a.length; j++) {
                if (chk.get(a[j]) != null) continue;
                chk.put(a[j], true);

                if (m.get(a[j]) >= (a[0] / 2 + 1)) {
                    System.out.println(a[j]);
                    flag = false;
                    break;
                }
            }

            if (flag) System.out.println("SYJKGW");
        }

		br.close();
	}
}