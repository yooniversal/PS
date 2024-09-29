import java.io.*;
import java.util.*;

public class Main {

    private static long[] cache = new long[100005];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int m = Integer.parseInt(input[1]);

            int sum = 0;
            
            for (int i=n; i<=m; i++) {
                int cur = i;
                if (cur == 0) {
                    sum++;
                    continue;
                }

                while (cur > 0) {
                    if (cur % 10 == 0) sum++;
                    cur /= 10;
                }
            }

            System.out.println(sum);
        }

		br.close();
	}
}