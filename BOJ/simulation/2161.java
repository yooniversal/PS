import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Queue<Integer> q = new LinkedList<>();
        int n = Integer.parseInt(br.readLine());
        for (int i=1; i<=n; i++) {
            q.add(i);
        }

        while (q.size() > 1) {
            int top = process(q);
            System.out.printf("%d ", top);
        }

        int top = q.poll();
        System.out.println(top);
    }

    static int process(Queue<Integer> q) {
        int ret = q.poll();
        int secondTop = q.poll();
        q.add(secondTop);
        return ret;
    }
}