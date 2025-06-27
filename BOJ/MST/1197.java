import java.io.*;
import java.util.*;

public class Main {

    static int v, e;
    static List<E> edges;
    static int[] uni;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        v = Integer.parseInt(inputs[0]);
        e = Integer.parseInt(inputs[1]);
        uni = new int[v+5];
        edges = new ArrayList<>();

        for (int i=1; i<=v; i++) uni[i] = i;

        for (int i=0; i<e; i++) {
            inputs = br.readLine().split(" ");
            int u = Integer.parseInt(inputs[0]);
            int v = Integer.parseInt(inputs[1]);
            int d = Integer.parseInt(inputs[2]);
            edges.add(new E(u, v, d));
        }
        Collections.sort(edges);

        int ret = 0;
        for (E edge : edges) {
            if (find(edge.u) == find(edge.v)) continue;
            makeUnion(edge.u, edge.v);
            ret += edge.d;
        }

        System.out.println(ret);
	}

    static int find(int n) {
        if (uni[n] == n) return n;
        return uni[n] = find(uni[n]);
    }

    static void makeUnion(int a, int b) {
        a = find(a); b = find(b);
        if (a < b) uni[b] = a;
        else uni[a] = b;
    }

    static class E implements Comparable<E> {
        int u;
        int v;
        int d;
        E(int u, int v, int d) {
            this.u = u;
            this.v = v;
            this.d = d;
        }

        @Override
        public int compareTo(E next) {
            return d - next.d;
        }
    }
}