import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] usedHotKey = new boolean[35];

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] strs = br.readLine().split(" ");

            boolean found = false;
            List<String> converted = new ArrayList<>();
            // 단어별 첫 글자 탐색
            for (String s : strs) {
                if (found || usedHotKey[charToIndex(s.charAt(0))]) {
                    converted.add(s);
                    continue;
                }

                converted.add("[" + s.charAt(0) + "]" + s.substring(1));
                usedHotKey[charToIndex(s.charAt(0))] = true;
                found = true;
            }

            if (!found) {
                // 왼쪽부터 오른쪽까지 하나씩 탐색
                StringBuilder sb = new StringBuilder();
                for (int i=0; i<strs.length; i++) {
                    sb.append(strs[i]);
                    if (i < strs.length-1) sb.append(" ");
                }
                String appendedStr = sb.toString();

                for (int i=0; i<appendedStr.length(); i++) {
                    char c = appendedStr.charAt(i);
                    if (c == ' ') continue;
                    if (usedHotKey[charToIndex(c)]) continue;
                    usedHotKey[charToIndex(c)] = true;

                    System.out.println(
                        appendedStr.substring(0, i) + "[" + appendedStr.charAt(i) + "]" + appendedStr.substring(i + 1)
                    );
                    found = true;
                    break;
                }

                if (!found) {
                    // 모두 단축키로 설정돼있으면 그대로 출력
                    System.out.println(appendedStr);
                }
            } else {
                // 첫 글자에서 단축키 설정됐으므로 출력
                for (String s : converted) {
                    System.out.print(s + " ");
                }
                System.out.println();
            }
        }
    }

    static int charToIndex(char c) {
        if ('A' <= c && c <= 'Z') return (int)(c - 'A');
        return (int)(c - 'a');
    }
}