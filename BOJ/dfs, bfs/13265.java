import java.io.*;
import java.util.*;

public class Main {

    static int[] color = new int[1005];
    static List<Integer>[] e = new ArrayList[1005];
    static boolean flag = true;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            init();

            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int m = Integer.parseInt(input[1]);

            while (m-- > 0) {
                String[] edge = br.readLine().split(" ");
                int u = Integer.parseInt(edge[0]);
                int v = Integer.parseInt(edge[1]);

                e[u].add(v);
                e[v].add(u);
            }

            for (int i=1; i<=n; i++) {
                if (color[i] != -1) continue;
                color[i] = 0;
                dfs(i);
            }

            if (flag) System.out.println("possible");
            else System.out.println("impossible");
        }

		br.close();
	}

    static void dfs(int cur) {
        if (!flag) return;
        
        int nextValue = color[cur] == 0 ? 1 : 0;
        for (Integer next : e[cur]) {
            if (color[next] != -1) {
                if (color[next] != nextValue) {
                    flag = false;
                    break;
                }
                continue;
            }
            color[next] = nextValue;
            dfs(next);
        }
    }

    static void init() {
        for (int i=0; i<=1000; i++) {
            color[i] = -1;
            e[i] = new ArrayList<Integer>();
        }
        flag = true;
    }
}