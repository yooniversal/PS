class Solution {

    private static int[] cache;

    public int numDecodings(String s) {
        cache = new int[105];
        for (int i=0; i<105; i++) cache[i] = -1;

        return f(s, 0);
    }

    public int f(String s, int cur) {
        if (cur < s.length() && s.charAt(cur) == '0') return 0;
        if (cur >= s.length()-1) return 1;
        if (cache[cur] != -1) return cache[cur];
        cache[cur] = 0;
        
        if (s.charAt(cur) == '1') {
            cache[cur] += f(s, cur+2);
        } else if (s.charAt(cur) == '2' && ('0' <= s.charAt(cur+1) && s.charAt(cur+1) <= '6')) {
            cache[cur] += f(s, cur+2);
        }
        
        cache[cur] += f(s, cur+1);
        return cache[cur];
    }
}
