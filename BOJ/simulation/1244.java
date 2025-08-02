import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int switchCnt = Integer.parseInt(br.readLine());
        String[] switchStatus = br.readLine().split(" ");

        int peopleCnt = Integer.parseInt(br.readLine());
        while (peopleCnt-- > 0) {
            String[] inputs = br.readLine().split(" ");
            int type = Integer.parseInt(inputs[0]);
            int number = Integer.parseInt(inputs[1]);

            changeStatus(switchStatus, type, number);
        }

        for (int i=0; i<switchStatus.length; i++) {
            System.out.print(switchStatus[i] + " ");
            if ((i+1) % 20 == 0 || i == switchStatus.length-1) System.out.println();
        }
    }

    static void changeStatus(String[] switchStatus, int type, int number) {
        if (type == 1) {
            for (int i=number; i<=switchStatus.length; i+=number) {
                switchStatus[i-1] = inverseStatus(switchStatus[i-1]);
            }
        } else {
            int left = number, right = number;
            for (int i=number, j=number; i>0 && j<=switchStatus.length; i--, j++) {
                if (switchStatus[i-1].equals(switchStatus[j-1])) {
                    left = i-1; right = j-1;
                } else {
                    break;
                }
            }
            for (int i=left; i<=right; i++) {
                switchStatus[i] = inverseStatus(switchStatus[i]);
            }
        }
    }

    static String inverseStatus(String v) {
        if (v.equals("0")) return "1";
        return "0";
    }
}