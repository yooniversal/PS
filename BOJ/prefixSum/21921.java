import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        
        List<Integer> a = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            a.add(Integer.parseInt(st.nextToken()));
        }
		
		long sum = 0L;
        int retCnt = 0;
        long maxValue = 0L;
        Queue<Integer> q = new LinkedList<>();

        List<Long> sumArr = new ArrayList<>();
		
		for (Integer v : a) {
			if (q.size() >= x) {
                sum -= q.poll();
            }
            q.offer(v);

            sum += v;
            maxValue = Math.max(maxValue, sum);

            if (q.size() >= x) {
                sumArr.add(sum);
            }
		}

        for (Long s : sumArr) {
            if (s == maxValue) {
                retCnt++;
            }
        }
		
        if (maxValue != 0L) {
            System.out.println(maxValue);
            System.out.println(retCnt);
        } else {
            System.out.println("SAD");
        }

		br.close();
	}
}