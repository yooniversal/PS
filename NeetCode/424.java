class Solution {
    public int characterReplacement(String s, int k) {
        int ret = 0;
        
        Map<Character, Integer> cnt = new HashMap<>();
        int maxCnt = 0;
        for (int l=0, r=0; r<s.length(); r++) {
            int rcnt = cnt.getOrDefault(s.charAt(r), 0) + 1;
            cnt.put(s.charAt(r), rcnt);
            maxCnt = Math.max(maxCnt, rcnt);

            if ((r-l+1) - maxCnt > k) {
                int lcnt = cnt.getOrDefault(s.charAt(l), 0);
                cnt.put(s.charAt(l), lcnt - 1);
                l++;
            }

            ret = Math.max(ret, r-l+1);
        }

        return ret;
    }
}
