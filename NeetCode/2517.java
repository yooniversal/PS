class Solution {
    public int maximumTastiness(int[] price, int k) {
        Arrays.sort(price);
        
        int ret = 0;
        
        int l = 0, r = price[price.length-1] - price[0];
        while (l <= r) {
            int m = (l + r) / 2;
            if (isValidTaste(price, k, m)) {
                l = m+1;
                ret = Math.max(ret, m);
            } else {
                r = m-1;
            }
        }

        return ret;
    }

    private boolean isValidTaste(int[] price, int k, int taste) {
        int ret = 1;
        int prev = 0;
        for (int i=1; i<price.length; i++) {
            if (price[i] - price[prev] >= taste) {
                ret++;
                prev = i;

                if (ret == k) {
                    return true;
                }
            }
        }

        return false;
    }
}
