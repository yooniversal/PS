import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Queue q = new Queue(n);

        while (n-- > 0) {
            String[] inputs = br.readLine().split(" ");
            if (inputs[0].equals("push")) {
                int x = Integer.parseInt(inputs[1]);
                q.push(x);
            } else if (inputs[0].equals("pop")) {
                System.out.println(q.pop());
            } else if (inputs[0].equals("size")) {
                System.out.println(q.size());
            } else if (inputs[0].equals("empty")) {
                System.out.println(q.isEmpty());
            } else if (inputs[0].equals("front")) {
                System.out.println(q.front());
            } else {
                System.out.println(q.back());
            }
        }
    }

    static class Queue {
        int[] arr;
        int front;
        int rear;
        
        public Queue(int n) {
            arr = new int[n+1];
            front = 0;
            rear = 0;
        }
        
        public void push(int x) {
            arr[rear++] = x;
        }

        public int pop() {
            if (size() <= 0) return -1;
            return arr[front++];
        }

        public int size() {
            if (rear >= front) return rear - front;
            return 0;
        }

        public int isEmpty() {
            if (size() <= 0) return 1;
            return 0;
        }

        public int front() {
            if (size() <= 0) return -1;
            return arr[front];
        }

        public int back() {
            if (size() <= 0) return -1;
            return arr[rear - 1];
        }
    }
}