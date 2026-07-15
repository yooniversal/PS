class Solution {
    public String longestPalindrome(String s) {
        if (s.length() == 1) return s;

        String ret = "";
        int maxLen = 0;

        for (int i=0; i<s.length(); i++) {
            if (maxLen == 0) {
                maxLen = 1;
                ret = s.substring(i, i+1);
            }

            for (int l=i-1, r=i+1; l>=0 && r<s.length(); l--, r++) {
                if (s.charAt(l) != s.charAt(r)) break;
                if (maxLen < r-l+1) {
                    maxLen = r-l+1;
                    ret = s.substring(l, r+1);
                }
            }
        }

        for (int i=0; i<s.length()-1; i++) {
            if (s.charAt(i) != s.charAt(i+1)) continue;
            if (maxLen < 2) {
                maxLen = 2;
                ret = s.substring(i, i+2);
            }

            for (int l=i-1, r=i+2; l>=0 && r<s.length(); l--, r++) {
                if (s.charAt(l) != s.charAt(r)) break;
                if (maxLen < r-l+1) {
                    maxLen = r-l+1;
                    ret = s.substring(l, r+1);
                }
            }
        }

        return ret;
    }
}
