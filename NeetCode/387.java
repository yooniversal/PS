class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> cntMap = new HashMap<>();
        Map<Character, Integer> indexMap = new HashMap<>();  

        for (int i=0; i<s.length(); i++) {
            if (!indexMap.containsKey(s.charAt(i))) {
                indexMap.put(s.charAt(i), i);
            }

            cntMap.put(s.charAt(i), cntMap.getOrDefault(s.charAt(i), 0) + 1);
        }

        for (int i=0; i<s.length(); i++) {
            if (cntMap.getOrDefault(s.charAt(i), 0) > 1) continue;
            return indexMap.get(s.charAt(i));
        }

        return -1;
    }
}
