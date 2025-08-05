import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int rowLen = Integer.parseInt(inputs[0]);
        int colLen = Integer.parseInt(inputs[1]);
        int t = Integer.parseInt(br.readLine());

        List<Integer> cutRows = new ArrayList<>();
        List<Integer> cutCols = new ArrayList<>();
        cutRows.add(0);
        cutRows.add(colLen);
        cutCols.add(0);
        cutCols.add(rowLen);

        while (t-- > 0) {
            inputs = br.readLine().split(" ");
            int type = Integer.parseInt(inputs[0]);
            int v = Integer.parseInt(inputs[1]);
            if (type == 0) {
                cutRows.add(v);
            } else {
                cutCols.add(v);
            }
        }
        
        Collections.sort(cutRows);
        Collections.sort(cutCols);

        int[] a = new int[cutRows.size()-1];
        for (int i=0; i<cutRows.size()-1; i++) {
            a[i] = cutRows.get(i+1) - cutRows.get(i);
        }

        int[] b = new int[cutCols.size()-1];
        for (int i=0; i<cutCols.size()-1; i++) {
            b[i] = cutCols.get(i+1) - cutCols.get(i);
        }

        int ret = 0;
        for (int aa : a) {
            for (int bb : b) {
                ret = Math.max(ret, aa * bb);
            }
        }

        System.out.println(ret);
    }
}