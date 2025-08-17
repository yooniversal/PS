import java.io.*;
import java.util.*;

public class Main {

    static List<Node>[] edges;
    static boolean[] chk;
    static int[] d;
    static int INF = 987654321;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int v = Integer.parseInt(inputs[0]);
        int e = Integer.parseInt(inputs[1]);
        int start = Integer.parseInt(br.readLine());

        edges = new ArrayList[v+5];
        chk = new boolean[v+5];
        for (int i=0; i<v+5; i++) {
            edges[i] = new ArrayList<>();
        }

        d = new int[v+5];
        for (int i=0; i<v+5; i++) d[i] = INF;

        for (int i=0; i<e; i++) {
            inputs = br.readLine().split(" ");
            int from = Integer.parseInt(inputs[0]);
            int to = Integer.parseInt(inputs[1]);
            int w = Integer.parseInt(inputs[2]);
            edges[from].add(new Node(to, w));
        }

        dijkstra(start);

        for (int i=1; i<=v; i++) {
            if (d[i] != INF) System.out.println(d[i]);
            else System.out.println("INF");
        }
    }

    static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        d[start] = 0;
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            
            if (chk[cur.v]) continue;
            chk[cur.v] = true;

            if (d[cur.v] < cur.w) continue;
            for (Node next : edges[cur.v]) {
                int nextDist = cur.w + next.w;
                if (d[next.v] > nextDist) {
                    d[next.v] = nextDist;
                    pq.offer(new Node(next.v, nextDist));
                }
            }
        }
    }

    static class Node implements Comparable<Node> {
        int v;
        int w;

        public Node(int v, int w) {
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Node next) {
            return this.w - next.w;
        }
    }
}