class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ret = 0;
        boolean chk[] = new boolean[128];

        int i=0, j=0;
        while (j < s.length()) {
            while (chk[s.charAt(j)]) {
                chk[s.charAt(i)] = false;
                i++;
            }
            chk[s.charAt(j)] = true;

            ret = Math.max(ret, j-i+1);
            j++;
        }

        return ret;
    }
}
