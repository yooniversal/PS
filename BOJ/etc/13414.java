import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        Map<String, Integer> idMap = new HashMap<>();

        List<S> a = new ArrayList<>();
        for (int i=0; i<m; i++) {
            String str = br.readLine();
            if (idMap.get(str) == null) {
                idMap.put(str, a.size());
                a.add(new S(str, i));
                continue;
            }
            a.get(idMap.get(str)).order = i;
        }
        Collections.sort(a);

        for (int i=0; i<n && i<a.size(); i++) {
            System.out.println(a.get(i).v);
        }

		br.close();
	}

    static class S implements Comparable<S> {
        String v;
        int order;

        public S(String v, int order) {
            this.v = v;
            this.order = order;
        }

        @Override
        public int compareTo(S other) {
            return Integer.compare(this.order, other.order);
        }
    }
}