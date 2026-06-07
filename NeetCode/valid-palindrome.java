class Solution {
    public boolean isPalindrome(String s) {
        String newStr = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        
        for (int i=0, j=newStr.length()-1; i<=j; i++, j--) {
            if (newStr.charAt(i) != newStr.charAt(j)) return false;
        }

        return true;
    }
}
