import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] parent;
    static List<Integer>[] child;
    static int[] level;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for (; T>0; T--) {
            N = Integer.parseInt(br.readLine());
            parent = new int[N+1];
            child = new ArrayList[N+1];
            for (int i=1; i<=N; i++) child[i] = new ArrayList<Integer>();
            level = new int[N+1];

            for (int i=0; i<N-1; i++) {
                String[] targets = br.readLine().split(" ");
                int parentNumber = Integer.parseInt(targets[0]);
                int childNumber = Integer.parseInt(targets[1]);
                parent[childNumber] = parentNumber;
                child[parentNumber].add(childNumber);
            }

            int root = 0;
            for (int i=1; i<=N; i++) {
                if (parent[i] > 0) continue;
                root = i;
                break;
            }

            initLevel(root, 0);

            String[] targets = br.readLine().split(" ");
            int u = Integer.parseInt(targets[0]);
            int v = Integer.parseInt(targets[1]);
            System.out.println(getCommonAncestor(u, v));
        }

		br.close();
	}

    static int getCommonAncestor(int u, int v) {
        // u가 level이 더 높도록 설정
        if (level[u] < level[v]) {
            int tmp = u;
            u = v;
            v = tmp;
        }

        // level 같을 때까지 u의 부모로 거슬러 올라감
        while (level[u] > level[v]) {
            u = parent[u];
        }

        // 공통 조상 찾을 때까지 탐색 진행
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }

        return u;
    }

    static void initLevel(int cur, int currentLevel) {
        level[cur] = currentLevel;
        for (int c : child[cur]) {
            initLevel(c, currentLevel + 1);
        }
    }
}