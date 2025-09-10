import java.io.*;
import java.util.*;

public class Main {

    static int INF = 987654321;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] mbtiList = br.readLine().split(" ");

            boolean finished = false;
            Map<String, Integer> mbtiCnt = new HashMap<>();
            for (String mbti : mbtiList) {
                int cnt = mbtiCnt.getOrDefault(mbti, 0);

                if (cnt >= 3) {
                    System.out.println(0);
                    finished = true;
                    break;
                }

                mbtiCnt.put(mbti, cnt + 1);
            }

            if (finished) continue;

            int ret = INF;

            for (int i=0; i<n; i++) {
                for (int j=i+1; j<n; j++) {
                    for (int k=j+1; k<n; k++) {
                        ret = Math.min(ret, getTripleDistance(mbtiList[i], mbtiList[j], mbtiList[k]));
                    }
                }
            }

            System.out.println(ret);
        }
    }

    static int getDistance(String a, String b) {
        int dist = 0;
        for (int i=0; i<4; i++) {
            if (a.charAt(i) != b.charAt(i)) dist++;
        }
        return dist;
    }

    static int getTripleDistance(String a, String b, String c) {
        return getDistance(a, b) + getDistance(b, c) + getDistance(a, c);
    }
}