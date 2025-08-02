class Solution {
    public int reverse(int x) {
        long ret = 0;
        String v = Integer.toString(x);
        for (int i=v.length()-1; i>=0; i--) {
            if (i > 0) {
                ret = ret * 10 + (int)(v.charAt(i) - '0');
            } else {
                if ('0' <= v.charAt(i) && v.charAt(i) <= '9') {
                    ret = ret * 10L + (int)(v.charAt(i) - '0');
                }
            }
        }
        if (x < 0) ret *= -1;
        if (ret < -2147483648L || ret > 2147483647L) return 0;
        return (int)ret;
    }
}