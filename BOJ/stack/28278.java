import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Stack stack = new Stack();
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String[] inputs = br.readLine().split(" ");
            if (inputs[0].equals("1")) {
                int x = Integer.parseInt(inputs[1]);
                stack.push(x);
            } else if (inputs[0].equals("2")) {
                System.out.println(stack.pop());
            } else if (inputs[0].equals("3")) {
                System.out.println(stack.size());
            } else if (inputs[0].equals("4")) {
                System.out.println(stack.isEmpty());
            } else {
                System.out.println(stack.top());
            }
        }
    }

    static class Stack {
        private int[] arr;
        private int size;

        public Stack() {
            arr = new int[1000005];
            size = 0;
        }

        public void push(int x) {
            arr[size] = x;
            size++;
        }

        public int pop() {
            if (isEmpty() == 1) return -1;
            int top = arr[size - 1];
            size--;
            return top;
        }

        public int size() {
            return size;
        }

        public int isEmpty() {
            return size <= 0 ? 1 : 0;
        }

        public int top() {
            if (isEmpty() == 1) return -1;
            return arr[size - 1];
        }
    }
}