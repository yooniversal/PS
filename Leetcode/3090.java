class Solution {
    public int maximumLengthSubstring(String s) {
        int ret = 0;

        Map<Character, Integer> cnt = new HashMap<>();
        for (int l=0, r=0; r<s.length(); r++) {
            char right = s.charAt(r);
            
            while (cnt.getOrDefault(right, 0) >= 2) {
                char left = s.charAt(l);
                cnt.put(left, cnt.get(left) - 1);
                l++;
            }
            
            cnt.put(right, cnt.getOrDefault(right, 0) + 1);
            ret = Math.max(ret, r - l + 1);
        }

        return ret;
    }
}
