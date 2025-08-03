import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int score = Integer.parseInt(inputs[1]);
        int p = Integer.parseInt(inputs[2]);

        int[] ranks = new int[n];
        if (n > 0) {
            inputs = br.readLine().split(" ");
            for (int i=0; i<n; i++) {
                int rank = Integer.parseInt(inputs[i]);
                ranks[i] = rank;
            }
        }

        System.out.println(getRank(ranks, p, score));
    }

    static int getRank(int[] ranks, int p, int score) {
        int ret = 1;

        for (int i=0; i<ranks.length; i++) {
            if (ranks[i] > score) {
                ret = i + 2;
            }
        }

        if (ret > p) return -1;
        if (ranks.length == p && ranks[ranks.length-1] == score) return -1;
        return ret;
    }
}