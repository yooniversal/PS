class Solution {
    public long gcdSum(int[] nums) {
        long[] prefixGcd = new long[nums.length];

        int mx = nums[0];
        for (int i=0; i<nums.length; i++) {
            mx = Math.max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        Arrays.sort(prefixGcd);

        long ret = 0L;
        for (int i=0, j=prefixGcd.length-1; i<=j; i++, j--) {
            if (i == j) continue;
            ret += gcd(prefixGcd[i], prefixGcd[j]);
        }

        return ret;
    }

    public long gcd(long a, long b) {
        if (a < b) {
            long t = a;
            a = b;
            b = t;
        }

        while (b != 0) {
            long t = a%b;
            a = b;
            b = t;
        }

        return a;
    }
}
