class Solution {
    public boolean checkDivisibility(int n) {
        int sum = 0, product = 1;
        int v = n;
        while (v > 0) {
            sum += v % 10;
            product *= v % 10;
            v /= 10;
        }

        return n % (sum + product) == 0;
    }
}
