class Solution {
    public int[] plusOne(int[] digits) {
        int[] ret = new int[digits.length];

        int a = 0;
        for (int i=digits.length-1; i>=0; i--) {
            if (i == digits.length-1) {
                int v = digits[i] + 1;
                if (v == 10) {
                    a = 1;
                    ret[i] = 0;
                } else {
                    ret[i] = v;
                }
            } else {
                int v = digits[i] + a;
                ret[i] = v % 10;
                if (v >= 10) a = 1;
                else a = 0;
            }
        }

        if (a == 1) {
            ret = new int[digits.length+1];
            ret[0] = 1;
        }

        return ret;
    }
}
