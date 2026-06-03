class Solution {
    public int maxProfit(int[] prices) {
        int ret = 0;

        for (int i=0; i<prices.length; i++) {
            for (int j=i+1; j<prices.length; j++) {
                ret = Math.max(ret, prices[j] - prices[i]);
            }
        }

        return ret;
    }
}
