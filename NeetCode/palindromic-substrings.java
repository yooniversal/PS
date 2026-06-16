class Solution {

    private static int[][] cache;

    public int countSubstrings(String s) {
        int ret = 0;
        
        cache = new int[1005][1005];
        for (int i=0; i<1005; i++) {
            for (int j=0; j<1005; j++) {
                cache[i][j] = -1;
            }
        }

        for (int i=0; i<s.length(); i++) f(s, i, i);

        for (int i=0; i<s.length(); i++) {
            for (int j=i; j<s.length(); j++) {
                if (cache[i][j] == 1) {
                    ret++;
                }
            }
        }

        return ret;
    }

    public int f(String s, int a, int b) {
        if (b < a || a < 0 || b >= s.length()) return 0;
        if (cache[a][b] != -1) return cache[a][b];
        cache[a][b] = s.charAt(a) == s.charAt(b) ? 1 : 0;
        if (cache[a][b] == 1) {
            if (a==b) f(s, a-1, b);
            if (a==b) f(s, a, b+1);
            f(s, a-1, b+1);
        }
        return cache[a][b];
    }
}
