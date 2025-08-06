import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        MinHeap heap = new MinHeap();
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            int x = Integer.parseInt(br.readLine());
            if (x == 0) {
                System.out.println(heap.pop());
            } else {
                heap.insert(x);
            }
        }
    }

    static class MinHeap {
        private long[] arr;
        private int lastIndex;

        public MinHeap() {
            arr = new long[100005];
            arr[0] = 3000000000L;
            lastIndex = 0;
        }

        public void insert(int x) {
            arr[++lastIndex] = x;

            int current = lastIndex;
            while (current != 1) {
                if (arr[getParentIndex(current)] > arr[current]) {
                    long tmp = arr[getParentIndex(current)];
                    arr[getParentIndex(current)] = arr[current];
                    arr[current] = tmp;
                    current = getParentIndex(current);
                } else {
                    break;
                }
            }
        }

        public long pop() {
            if (lastIndex == 0) return 0;
            long root = arr[1];
            arr[1] = arr[lastIndex--];

            int current = 1;

            while (true) {
                long left = arr[getLeftChildIndex(current)];
                long right = arr[getRightChildIndex(current)];
                if (left <= right && arr[current] > left) {
                    arr[getLeftChildIndex(current)] = arr[current];
                    arr[current] = left;
                    current = getLeftChildIndex(current);
                } else if (left > right && arr[current] > right) {
                    arr[getRightChildIndex(current)] = arr[current];
                    arr[current] = right;
                    current = getRightChildIndex(current);
                } else {
                    break;
                }
            }

            return root;
        }

        private int getParentIndex(int x) {
            if ((x / 2) > lastIndex) return 0;
            return x / 2;
        }

        private int getLeftChildIndex(int x) {
            if ((x * 2) > lastIndex) return 0;
            return x * 2;
        }

        private int getRightChildIndex(int x) {
            if ((x * 2 + 1) > lastIndex) return 0;
            return x * 2 + 1;
        }
    }
}