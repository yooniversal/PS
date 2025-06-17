import java.io.*;
import java.util.*;

public class Main {

    static int[] path;
    static List<Integer>[] reversePaths;
    static int n;
    static long[] sheepCounts;
    static int maxLevel;
    static List<Integer>[] nodesByLevel;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        path = new int[n+1];
        sheepCounts = new long[n+1];
        maxLevel = 0;

        reversePaths = new ArrayList[n+1];
        nodesByLevel = new ArrayList[n+1];
        for (int i=0; i<=n; i++) {
            reversePaths[i] = new ArrayList<>();
            nodesByLevel[i] = new ArrayList<>();
        }
        

        for (int i=2; i<=n; i++) {
            String[] input = br.readLine().split(" ");
            String t = input[0];
            int a = Integer.parseInt(input[1]);
            int p = Integer.parseInt(input[2]);

            if (t.equals("S")) {
                sheepCounts[i] = a;
            } else {
                sheepCounts[i] = -a;
            }

            path[i] = p;
            reversePaths[p].add(i);
        }

        initLevel();

        while (maxLevel > 0) {
            for (int i=0; i<nodesByLevel[maxLevel].size(); i++) {
                int number = nodesByLevel[maxLevel].get(i);
                if (sheepCounts[number] <= 0) continue;

                sheepCounts[path[number]] += sheepCounts[number];
            }

            maxLevel--;
        }

        long result = sheepCounts[1] > 0L ? sheepCounts[1] : 0L;
        System.out.println(result);

		br.close();
	}

    static void initLevel() {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(1, 0));

        while (!q.isEmpty()) {
            Node cur = q.poll();
            nodesByLevel[cur.level].add(cur.number);

            for (int i=0; i<reversePaths[cur.number].size(); i++) {
                int nextNumber = reversePaths[cur.number].get(i);
                q.add(new Node(nextNumber, cur.level + 1));
                maxLevel = Math.max(maxLevel, cur.level + 1);
            }
        }
    }

    static class Node {
        int number;
        int level;

        Node(int n, int l) {
            number = n; level = l;
        }
    }
}