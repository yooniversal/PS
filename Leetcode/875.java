class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        long l = 1, r = 1_000_000_000;
        long ret = r;

        while (l <= r) {
            long m = (l+r) / 2;

            long sum = 0;
            for (int pile : piles) {
                sum += pile / m;
                if (pile % m != 0) {
                    sum++;
                }
            }

            if (sum <= h) {
                ret = Math.min(ret, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return (int) ret;
    }
}
