class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        int[] sCnt = new int[26];
        int[] tCnt = new int[26];

        for (int i=0; i<s.length(); i++) {
            int index = (int) (s.charAt(i) - 'a');
            sCnt[index]++;
        }

        for (int i=0; i<t.length(); i++) {
            int index = (int) (t.charAt(i) - 'a');
            tCnt[index]++;
        }

        for (int i=0; i<26; i++) {
            if (sCnt[i] != tCnt[i]) return false;
        }

        return true;
    }
}
