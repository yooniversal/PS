class Solution {
    public int maxProduct(int[] nums) {
        int ret = -987654321;
        int n = nums.length;
        int[][] products = new int[n][n];

        for (int i=0; i<n; i++) {
            int cur = 1;
            for (int j=i; j<n; j++) {
                cur *= nums[j];
                products[i][j] = cur;
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                ret = Math.max(ret, products[i][j]);
            }
        }

        return ret;
    }
}
