import java.io.*;
import java.util.*;

public class Main {

    static int INF = 987654321;
    static int lastIndex = -1;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n+1];
        int[] ret = new int[n+1];

        String[] v = br.readLine().split(" ");
        for (int i=0; i<n; i++) {
            arr[i] = Integer.parseInt(v[i]);
            ret[i] = INF;
        }

        for (int i=0; i<n; i++) {
            binary_search(ret, arr[i]);
        }

        System.out.println(lastIndex + 1);
	}

    static void binary_search(int[] ret, int v) {
        int s = 0, e = lastIndex == -1 ? 0 : lastIndex;
        int mid = (s + e) / 2;
        int target = -1;
        while (s <= e) {
            mid = (s + e) / 2;
            if (ret[mid] == v) return;
            if (ret[mid] < v) {
                s = mid + 1;
            } else {
                target = mid;
                e = mid - 1;
            }
        }

        if (ret[s] == INF) {
            ret[s] = v;
            lastIndex = s;
        } else {
            ret[target] = v;
        }
    }
}