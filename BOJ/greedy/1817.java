import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int m = Integer.parseInt(inputs[1]);

        if (n == 0) {
            System.out.println(0);
            return;
        }
        
        inputs = br.readLine().split(" ");
        int[] books = new int[n+5];
        for (int i=0; i<n; i++) {
            books[i] = Integer.parseInt(inputs[i]);
        }

        int ret = 0;
        int remainSize = m;
        for (int i=0; i<n; i++) {
            if (remainSize < books[i]) {
                ret++;
                remainSize = m;
            }
            remainSize -= books[i];
        }
        ret++;

        System.out.println(ret);
	}
}