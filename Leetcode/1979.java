class Solution {
    public int findGCD(int[] nums) {
        int minn = 1005;
        int maxx = 0;
        for (int n : nums) {
            minn = Math.min(minn, n);
            maxx = Math.max(maxx, n);
        }

        while (minn != 0) {
            int t = maxx % minn;
            maxx = minn;
            minn = t;
        }

        return maxx;
    }
}
