class Solution {
    public int[] minOperations(String boxes) {
        int[] ret = new int[boxes.length()];

        for (int i=0; i<boxes.length(); i++) {
            ret[i] = getOps(boxes, i);
        }

        return ret;
    }

    public int getOps(String boxes, int cur) {
        int count = 0;

        for (int i=0; i<boxes.length(); i++) {
            if (i == cur || boxes.charAt(i) == '0') continue;
            count += Math.abs(i - cur);
        }

        return count;
    }
}