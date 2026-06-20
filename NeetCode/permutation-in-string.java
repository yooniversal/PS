class Solution {
    public boolean checkInclusion(String s1, String s2) {
        Map<Character, Integer> s1Map = new HashMap<>();
        
        for (int i=0; i<s1.length(); i++) {
            char c = s1.charAt(i);
            s1Map.put(c, s1Map.getOrDefault(c, 0) + 1);
        }

        for (int i=0; i<s2.length(); i++) {
            if (isPermut(s2, i, new HashMap<>(s1Map), s1.length())) {
                return true;
            }
        }

        return false;
    }

    public boolean isPermut(String s, int start, Map<Character, Integer> map, int maxCnt) {
        int cnt = 0;
        for (int i=start; i<s.length(); i++) {
            if (map.getOrDefault(s.charAt(i), 0) == 0) return false;
            map.put(s.charAt(i), map.get(s.charAt(i)) - 1);
            cnt++;

            if (cnt == maxCnt) return true;
        }

        return false;
    }
}
