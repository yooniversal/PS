import java.io.*;
import java.util.*;

public class Main {

    static boolean[] chk;
    static List<Integer>[] hate;
    static List<Integer> blueTeam;
    static List<Integer> whiteTeam;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
        chk = new boolean[n+1];
        hate = new ArrayList[n+1];
        for (int i=1; i<=n; i++) hate[i] = new ArrayList<>();
        blueTeam = new ArrayList<>();
        whiteTeam = new ArrayList<>();

        for (int i=1; i<=n; i++) {
            String[] v = br.readLine().split(" ");
            int len = Integer.parseInt(v[0]);
            for (int j=1; j<=len; j++) {
                int target = Integer.parseInt(v[j]);
                hate[i].add(target);
                hate[target].add(i);
            }
        }

        for (int i=1; i<=n; i++) {
            if (chk[i]) continue;
            chk[i] = true;
            dfs(i, true);
        }

        Collections.sort(blueTeam);
        Collections.sort(whiteTeam);

        System.out.println(blueTeam.size());
        for (int person : blueTeam) System.out.printf("%d ", person);
        System.out.println();

        System.out.println(whiteTeam.size());
        for (int person : whiteTeam) System.out.printf("%d ", person);
        System.out.println();
	}

    static void dfs(int cur, boolean isBlue) {
        if (isBlue) blueTeam.add(cur);
        else whiteTeam.add(cur);

        for (int next : hate[cur]) {
            if (chk[next]) continue;
            chk[next] = true;
            dfs(next, !isBlue);
        }
    }
}