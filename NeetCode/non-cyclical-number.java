class Solution {
    public boolean isHappy(int n) {
        Map<Integer, Boolean> chk = new HashMap<>();
        while (true) {
            n = doHappy(n);
            if (n == 1) return true;
            if (chk.getOrDefault(n, false)) break;
            chk.put(n, true);
        }

        return false;
    }

    private int doHappy(int n) {
        int ret = 0;
        while (n > 0) {
            int v = n % 10;
            ret += v*v;
            n /= 10;
        }

        return ret;
    }
}
