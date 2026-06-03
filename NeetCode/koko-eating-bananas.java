class Solution {

    private static int MAX_K = 1000000000;

    public int minEatingSpeed(int[] piles, int h) {
        return binarySearch(1, MAX_K, piles, h);
    }

    public int binarySearch(int l, int r, int[] piles, int h) {
        int ret = r;

        int m = (l + r) / 2;
        while (l < r) {
            m = (l + r) / 2;
            if (pass(piles, m, h)) {
                if (ret > m) ret = m;
                r = m;
            } else {
                l = m+1;
            }
        }

        return ret;
    }

    public boolean pass(int[] piles, int k, int h) {
        int ret = 0;

        for (int p : piles) {
            if (p % k == 0) ret += p / k;
            else ret += p / k + 1;
        }

        return ret <= h;
    }
}
