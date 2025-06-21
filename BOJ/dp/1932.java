import java.io.*;
import java.util.*;

public class Main {

    static int[][] cache;
    static int n;
    static int[][] a;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        a = new int[n+5][n+5];

        cache = new int[n+5][n+5];
        for (int i=0; i<n+5; i++) {
            for (int j=0; j<n+5; j++) {
                cache[i][j] = -1;
            }
        }
        
        for (int i=0; i<n; i++) {
            String[] v = br.readLine().split(" ");
            for (int j=0; j<=i; j++) {
                a[i][j] = Integer.parseInt(v[j]);
            }
        }

        int ret = 0;
        for (int i=0; i<n; i++) {
            ret = Math.max(ret, f(n-1, i));
        }
        System.out.println(ret);

		br.close();
	}

    static int f(int row, int col) {
        if (col < 0) return 0;
        if (row == 0) return a[0][0];
        if (cache[row][col] != -1) return cache[row][col];
        cache[row][col] = 0;

        cache[row][col] = Math.max(f(row-1, col-1), f(row-1, col)) + a[row][col];

        return cache[row][col];
    }
}