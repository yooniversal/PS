class Solution {
    public boolean sumGame(String num) {
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;
        for (int i=0; i<num.length(); i++) {
            if (num.charAt(i) == '?') {
                if (i < num.length() / 2) {
                    leftQ++;
                } else {
                    rightQ++;
                }
            } else {
                int n = (int)(num.charAt(i) - '0');
                if (i < num.length() / 2) {
                    leftSum += n;
                } else {
                    rightSum += n;
                }
            }
        }

        int minQ = Math.min(leftQ, rightQ);
        leftQ -= minQ;
        rightQ -= minQ;

        int aliceQ = 0, bobQ = 0;
        if (leftQ > 0) {
            aliceQ = leftQ % 2;
            leftSum += leftQ / 2 * 9;
            if (leftSum > rightSum) return true;
        } else if (rightQ > 0) {
            aliceQ = rightQ % 2;
            rightSum += rightQ / 2 * 9;
            if (rightSum > leftSum) return true;
        }

        if (aliceQ > 0) return true;
        return leftSum != rightSum;
    }
}
