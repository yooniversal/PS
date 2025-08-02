class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        String v = Integer.toString(x);
        for (int i=0, j=v.length()-1; i<=j; i++, j--) {
            if (v.charAt(i) != v.charAt(j)) return false;
        }
        return true;
    }
}