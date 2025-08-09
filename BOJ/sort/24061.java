import java.io.*;
import java.util.*;

public class Main {

    static boolean finished = false;
    static int sortedCnt = 0;
    static int k;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        k = Integer.parseInt(inputs[1]);
        int[] arr = new int[n];

        inputs = br.readLine().split(" ");
        for (int i=0; i<inputs.length; i++) {
            int v = Integer.parseInt(inputs[i]);
            arr[i] = v;
        }

        mergeSort(arr, 0, arr.length-1);

        if (!finished) {
            System.out.println(-1);
        }
    }

    static void mergeSort(int[] arr, int p, int r) {
        if (p >= r || finished) return;
        int q = (p + r) / 2;
        // System.out.printf("p:%d q:%d r:%d\n", p, q, r);
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }

    static void merge(int[] arr, int p, int q, int r) {
        if (finished) return;
        int[] tmp = new int[r - p + 1];
        
        int i = p, j = q+1, t = 0;
        // 큰 순으로 각 포인터에서 처리
        while (i <= q && j <= r) {
            if (arr[i] <= arr[j]) tmp[t++] = arr[i++];
            else tmp[t++] = arr[j++];
        }

        // 남은 것 처리
        while (i <= q) tmp[t++] = arr[i++];
        while (j <= r) tmp[t++] = arr[j++];

        for (i=0; i<t; i++) {
            arr[p + i] = tmp[i];

            if (!finished && ++sortedCnt == k) {
                finished = true;
                for (int a : arr) {
                    System.out.printf("%d ", a);
                }
                System.out.println();
                break;
            }
        }
    }
}