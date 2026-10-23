class Solution {
    public String longestPalindrome(String s) {
        String ret = "";
        int maxCount = 0;

        for (int i=0; i<s.length(); i++) {
            int j=i, k=i;
            for (; j>=0 && k<s.length(); j--, k++) {
                if (s.charAt(j) != s.charAt(k)) break;
            }
            j++; k--;

            if (maxCount < k-j+1) {
                maxCount = k-j+1;
                ret = s.substring(j, k+1);
            }
        }

        for (int i=0; i<s.length()-1; i++) {
            if (s.charAt(i) != s.charAt(i+1)) continue;

            int j=i, k=i+1;
            for (; j>=0 && k<s.length(); j--, k++) {
                if (s.charAt(j) != s.charAt(k)) break;
            }
            j++; k--;

            if (maxCount < k-j+1) {
                maxCount = k-j+1;
                ret = s.substring(j, k+1);
            }
        }

        return ret;
    }
}
