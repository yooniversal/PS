class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1) return s.length();

        int ret = 1;

        Map<Character, Integer> map = new HashMap<>();
        map.put(s.charAt(0), 1);
        for (int i=0, j=1; i<s.length() && j<s.length();) {
            char a = s.charAt(i);
            char b = s.charAt(j);
            if (map.getOrDefault(b, 0) == 0) {
                ret = Math.max(ret, j-i+1);
                map.put(b, map.getOrDefault(b, 0) + 1);
                j++;
            } else {
                map.put(a, map.getOrDefault(a, 0)-1);
                i++;
            }
        }

        return ret;
    }
}
