import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Person[] arr = new Person[n];

        for (int i=0; i<n; i++) {
            int v = Integer.parseInt(br.readLine());
            arr[i] = new Person(i, v);
        }

        Person target = arr[0];
        int cnt = 0;
        while (true) {
            Arrays.sort(arr);
            if (arr[0] == target) break;
            arr[0].votes--;
            target.votes++;
            cnt++;
        }

        System.out.println(cnt);
    }

    static class Person implements Comparable<Person> {
        int id;
        int votes;

        public Person(int id, int votes) {
            this.id = id;
            this.votes = votes;
        }

        @Override
        public int compareTo(Person p) {
            if (p.votes != votes) return p.votes - votes;
            return p.id - id;
        }
    }
}