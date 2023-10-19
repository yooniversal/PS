import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int[] lifes;
    static int[] happies;
    static int[][] cache = new int[105][25];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        lifes = new int[25];
        happies = new int[25];

        for (int i=0; i<105; ++i) for (int j=0; j<25; ++j) {
            cache[i][j] = -1;
        }

        input = br.readLine().split(" ");
        for (int i=0; i<n; ++i) {
            lifes[i] = Integer.parseInt(input[i]);
        }

        input = br.readLine().split(" ");
        for (int i=0; i<n; ++i) {
            happies[i] = Integer.parseInt(input[i]);
        }

        System.out.println(f(100, 0));
    }

    static int f(int life, int cur) {
        if (life <= 0 || cur >= n) return 0;
        if (cache[life][cur] != -1) return cache[life][cur];
        cache[life][cur] = 0;

        if(life - lifes[cur] > 0) {
            cache[life][cur] = Math.max(cache[life][cur], f(life - lifes[cur], cur + 1) + happies[cur]);
        }
        cache[life][cur] = Math.max(cache[life][cur], f(life, cur + 1));

        return cache[life][cur];
    }
}
