import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String x = br.readLine();
        
        int sumOfDigits = 0;
        int interation = 0;

        if (x.length() <= 1) {
            System.out.println(0);
            if (Integer.parseInt(x) % 3 == 0) System.out.println("YES");
            else System.out.println("NO");
            return;
        }

        do {
            sumOfDigits = getSumOfDigits(x);
            x = Integer.toString(sumOfDigits);
            interation++;
        } while (sumOfDigits >= 10);

        System.out.println(interation);
        if (sumOfDigits % 3 == 0) System.out.println("YES");
        else System.out.println("NO");
    }

    static int getSumOfDigits(String x) {
        int ret = 0;

        for (int i=0; i<x.length(); i++) {
            int digit = x.charAt(i) - '0';
            ret += digit;
        }

        return ret;
    }
}