class Solution {
    public int maxProduct(int[] nums) {
        int ret = -100;

        int minProduct = 1;
        int maxProduct = 1;
        for (int n : nums) {
            int nMinProduct = minProduct * n;
            int nMaxProduct = maxProduct * n;
            minProduct = Math.min(nMinProduct, Math.min(nMaxProduct, n));
            maxProduct = Math.max(nMinProduct, Math.max(nMaxProduct, n));
            ret = Math.max(ret, Math.max(minProduct, maxProduct));
        }

        return ret;
    }
}
